#include <libxml/parser.h>

#include "input_state.h"

#define ROOT BAD_CAST "pt"

#define DEBUG 0

static char const *
state_enum_name (enum state num)
{
  switch (num)
    {
    case TOKEN:  return "TOKEN";
    case STRUCT: return "STRUCT";
    case MEMBER: return "MEMBER";
    default:     return "<unknown>";
    }
}

static void
push_state (struct xml_input_state *state, enum state num)
{
  if (DEBUG)
    printf ("push (%s)\n", state_enum_name (num));
  stack_push (state->state_stack, (void *)num);
}

static enum state
pop_state (struct xml_input_state *state)
{
  enum state num = (enum state)stack_pop (state->state_stack);
  if (DEBUG)
    printf ("pop (%s)\n", state_enum_name (num));
  return num;
}


static void
xml_input_startDocument (void *ctx)
{
  struct xml_input_state *state = ctx;
  assert (state->root == NULL);
  assert (state->node_stack == NULL);
  assert (state->state_stack == NULL);
  state->node_stack = array_stack_new ();
  state->state_stack = stack_new ();

  /* initial level for the root node */
  array_stack_push_level (state->node_stack);
}

static void
xml_input_endDocument (void *ctx)
{
  struct xml_input_state *state = ctx;
  assert (state->root == NULL);
  assert (state->node_stack != NULL);
  assert (state->state_stack != NULL);

  if (array_stack_levels (state->node_stack) != 1)
    {
      /* parsing failed, clean up the already parsed nodes */
      do
        {
          while (array_stack_size (state->node_stack) != 0)
            pt_node_unref_ornull (array_stack_pop (state->node_stack));
          array_stack_pop_level (state->node_stack);
        }
      while (array_stack_levels (state->node_stack) != 0);
    }
  else
    {
      /* parsing succeeded, there must be exactly one node in the array stack */
      assert (array_stack_size (state->node_stack) == 1);
      assert (stack_size (state->state_stack) == 0);

      /* refcounts were never changed, it should be 1
       * we can return it and the caller will gain ownership of this reference
       */
      state->root = array_stack_last (state->node_stack);
    }

  /* clear data structures used during parsing
   */
  array_stack_delete (state->node_stack);
  stack_delete (state->state_stack);
  mem_free (state->token.text.data, state->token.text.capacity + 1);
}

static void
xml_input_startElement ( void *ctx
                       , const xmlChar *name
                       , const xmlChar **atts)
{
  struct xml_input_state *state = ctx;
  assert (state != NULL);
  assert (name != NULL);

  if (xmlStrcmp (name, ROOT) == 0)
    return;

  /* "token" with attributes is a token, without attributes, it's a member */
  if (xmlStrcmp (name, BAD_CAST "token") == 0 && atts != NULL)
    {
      push_state (state, TOKEN);

      assert (atts[0] != NULL); assert (atts[1] != NULL);
      assert (xmlStrcmp (atts[0], BAD_CAST "left") == 0);
      sscanf ( (char const *)atts[1], "%d:%d"
             , &state->token.location.first_line
             , &state->token.location.first_column
             );

      assert (atts[2] != NULL); assert (atts[3] != NULL);
      assert (xmlStrcmp (atts[2], BAD_CAST "right") == 0);
      sscanf ( (char const *)atts[3], "%d:%d"
             , &state->token.location.last_line
             , &state->token.location.last_column
             );

      assert (atts[4] != NULL); assert (atts[5] != NULL);
      assert (xmlStrcmp (atts[4], BAD_CAST "token") == 0);
      sscanf ((char const *)atts[5], "%d", &state->token.token);

      assert (atts[6] == NULL);
    }
  else
    {
      /* if we have attributes, this is a constructor */
      if (atts != NULL)
        {
          size_t members = 0;
          push_state (state, STRUCT);

          assert (atts[0] != NULL); assert (atts[1] != NULL);
          assert (xmlStrcmp (atts[0], BAD_CAST "members") == 0);

          sscanf ((char const *)atts[1], "%zd", &members);
          assert (members > 0);

          /* new level for this constructor */
          array_stack_push_level (state->node_stack);

          assert (atts[2] == NULL);
        }
      else
        {
          push_state (state, MEMBER);
          state->empty_child = true;
        }
    }

  if (DEBUG)
    {
      xmlChar const **it;
      printf ("%p->%s (%s, {", state, __func__, name);
      if (atts)
        for (it = atts; *it != NULL; it += 2)
          {
            printf ("%s: %s", it[0], it[1]);
            if (it[2] != NULL)
              printf (", ");
          }
      printf ("})\n");
    }
}

static void
xml_input_endElement ( void *ctx
                     , const xmlChar *name)
{
  struct xml_input_state *state = ctx;
  assert (state != NULL);
  assert (name != NULL);

  if (xmlStrcmp (name, ROOT) == 0)
    return;

  if (DEBUG)
    {
      printf ("%p->%s (%s)\n", state, __func__, name);
      printf ( "   levels: %zd size: %zd\n"
             , array_stack_levels (state->node_stack)
             , array_stack_size   (state->node_stack));
    }

  switch (pop_state (state))
    {
    case TOKEN:
      {
        pt_node *token = pt_token_new ( &state->token.location
                                      , (char const *)state->token.text.data
                                      , state->token.text.length
                                      , state->token.token
                                      );
        state->token.text.length = 0;
        array_stack_push (state->node_stack, token);
        break;
      }
    case STRUCT:
      {
        size_t i;
        pt_node *node;
        void *const *argv = array_stack_last_level (state->node_stack);
        size_t argc = array_stack_size (state->node_stack);
        assert (argv != NULL);

        if (DEBUG)
          {
            printf ("pt_%s_new (", (char const *)name);
            for (i = 0; i < argc - 1; i++)
              printf ("%p, ", argv[i]);
            printf ("%p) = ", argv[i]);
            fflush (stdout);
          }
        node = pt_new ((char const *)name, (pt_node *const *)argv);
        assert (node != NULL);
        if (DEBUG)
          printf ("%p\n", node);

        for (i = 0; i < argc; i++)
          pt_node_unref_ornull (argv[i]);
        array_stack_pop_level (state->node_stack);

        array_stack_push (state->node_stack, node);
        break;
      }
    case MEMBER:
      {
        if (state->empty_child)
          {
            if (DEBUG)
              puts ("empty member, pushing NULL");
            array_stack_push (state->node_stack, NULL);
          }
        break;
      }
    default:
      {
        assert (!"bad case");
      }
    }

  if (0 && DEBUG)
    {
      printf ("now:\n");
      printf ( "   levels: %zd size: %zd\n"
             , array_stack_levels (state->node_stack)
             , array_stack_size   (state->node_stack));
    }

  state->empty_child = false;
}

static void
xml_input_characters ( void *ctx
                     , const xmlChar *ch
                     , int len)
{
  struct xml_input_state *state = ctx;
  assert (state != NULL);
  assert (ch != NULL);
  assert (len > 0);

  if (state->token.text.capacity - state->token.text.length - len < 0)
    {
      state->token.text.data = mem_realloc ( state->token.text.data
                                           , state->token.text.capacity + len + 1);
      state->token.text.capacity += len;
    }
  if (state->token.text.length == 0)
    state->token.text.data[0] = '\0';
  /* FIXME: use xmlStrncat, instead */
#if 0
  xmlStrncat (state->token.text.data, ch, len);
#else
  memcpy ( state->token.text.data + state->token.text.length
         , ch
         , len);
#endif
  state->token.text.length += len;
  state->token.text.data[state->token.text.length] = '\0';

  assert (xmlStrlen (state->token.text.data) == state->token.text.length);
}


static void
xml_input_comment ( void *ctx
                  , const xmlChar *value)
{
  struct xml_input_state *state = ctx;
  assert (state != NULL);
  assert (value != NULL);

  printf ("%p->%s (%s)\n", state, __func__, value);
}

static void
xml_input_warning ( void *ctx
                  , const char *msg, ...)
{
  struct xml_input_state *state = ctx;
  va_list ap;
  assert (state != NULL);
  assert (msg != NULL);

  fprintf (stdout, "%p: warning: ", state->root);
  va_start (ap, msg);
  vfprintf (stdout, msg, ap);
  va_end (ap);
}

static void
xml_input_error ( void *ctx
                , const char *msg, ...)
{
  struct xml_input_state *state = ctx;
  va_list ap;
  assert (state != NULL);
  assert (msg != NULL);

  fprintf (stdout, "%p: error: ", state->root);
  va_start (ap, msg);
  vfprintf (stdout, msg, ap);
  va_end (ap);
}


xmlSAXHandler const xml_input_handler = {
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  xml_input_startDocument,
  xml_input_endDocument,
  xml_input_startElement,
  xml_input_endElement,
  NULL,
  xml_input_characters,
  NULL,
  NULL,
  xml_input_comment,
  xml_input_warning,
  xml_input_error,
  NULL,
  NULL,
  NULL,
  NULL,
  0,
  /* The following fields are extensions available only on version 2 */
  NULL,
  NULL,
  NULL,
  NULL,
};
