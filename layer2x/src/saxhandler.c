#include <libxml/parser.h>

#include "input_state.h"

#define ROOT BAD_CAST "pt"

static void
push_state (struct xml_input_state *state, enum state num)
{
  stack_push (state->state_stack, (void *)num);
}

static enum state
pop_state (struct xml_input_state *state)
{
  return (enum state)stack_pop (state->state_stack);
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
}

static void
xml_input_endDocument (void *ctx)
{
  struct xml_input_state *state = ctx;
  if (0)
  assert (state->root == NULL);
  assert (state->node_stack != NULL);
  assert (array_stack_levels (state->node_stack) == 1);
  assert (array_stack_size (state->node_stack) == 1);
  assert (state->state_stack != NULL);
  assert (stack_size (state->state_stack) == 0);

  state->root = array_stack_last (state->node_stack);

  array_stack_delete (state->node_stack);
  stack_delete (state->state_stack);
  xfree (state->token.text.data, state->token.text.capacity);
}

static void
xml_input_startElement ( void *ctx
                       , const xmlChar *name
                       , const xmlChar **atts)
{
  struct xml_input_state *state = ctx;

  if (xmlStrcmp (name, ROOT) == 0)
    return;

  state->empty_child = 0;

  if (xmlStrcmp (name, BAD_CAST "token") == 0)
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
          state->empty_child = 1;
        }
    }

#if 0
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
#endif
}

static void
xml_input_endElement ( void *ctx
                     , const xmlChar *name)
{
  struct xml_input_state *state = ctx;

  if (xmlStrcmp (name, ROOT) == 0)
    return;

#if 0
  printf ("%p->%s (%s)\n", state, __func__, name);
  printf ( "levels: %zd size: %zd, "
         , array_stack_levels (state->node_stack)
         , array_stack_size   (state->node_stack));
#endif
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
        pt_node *node;
        void *const *args = array_stack_last_level (state->node_stack);
        assert (args != NULL);

        node = pt_new ((char const *)name, (pt_node *const *)args);

        array_stack_pop_level (state->node_stack);

        array_stack_push (state->node_stack, node);
        break;
      }
    case MEMBER:
      {
        if (state->empty_child)
          array_stack_push (state->node_stack, NULL);
        break;
      }
    default:
      {
        assert (!"bad case");
      }
    }
}

static void
xml_input_characters ( void *ctx
                     , const xmlChar *ch
                     , int len)
{
  struct xml_input_state *state = ctx;

  if (state->token.text.capacity - state->token.text.length - len < 0)
    {
      state->token.text.data = xrealloc ( state->token.text.data
                                        , state->token.text.capacity + len);
      state->token.text.capacity += len;
    }
  if (state->token.text.length == 0)
    state->token.text.data[0] = '\0';
  xmlStrncat (state->token.text.data, ch, len);
  state->token.text.length += len;
}


static void
xml_input_comment ( void *ctx
                  , const xmlChar *value)
{
  struct xml_input_state *state = ctx;

  printf ("%p->%s (%s)\n", state, __func__, value);
}

static void
xml_input_warning ( void *ctx
                  , const char *msg, ...)
{
  va_list ap;
  struct xml_input_state *state = ctx;

  fprintf (stdout, "%p: warning: ", state->root);
  va_start (ap, msg);
  vfprintf (stdout, msg, ap);
  va_end (ap);
}

static void
xml_input_error ( void *ctx
                , const char *msg, ...)
{
  va_list ap;
  struct xml_input_state *state = ctx;

  fprintf (stdout, "%p: error: ", state->root);
  va_start (ap, msg);
  vfprintf (stdout, msg, ap);
  va_end (ap);
}


xmlSAXHandler xml_input_handler = {
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
