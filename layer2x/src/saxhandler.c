#include <libxml/parser.h>

#include "input_state.h"


static void
xml_input_startDocument (void *ctx)
{
  struct xml_input_state *state = ctx;
  assert (state->root == NULL);
  assert (state->stack == NULL);
}

static void
xml_input_endDocument (void *ctx)
{
  struct xml_input_state *state = ctx;
  if (0)
  assert (state->root == NULL);
  assert (state->stack == NULL);
}

static void
xml_input_startElement ( void *ctx
                       , const xmlChar *name
                       , const xmlChar **atts)
{
  struct xml_input_state *state = ctx;
  xmlChar const **it;

  if (xmlStrcmp (name, BAD_CAST "token") == 0)
    {
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
          assert (atts[0] != NULL); assert (atts[1] != NULL);
          assert (xmlStrcmp (atts[0], BAD_CAST "members") == 0);

          sscanf ((char const *)atts[1], "%zd", &members);
          assert (members > 0);

          /* TODO: allocate an array with `members´ elements and stack it
           * into the state */

          assert (atts[2] == NULL);
        }
    }

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

static void
xml_input_endElement ( void *ctx
                     , const xmlChar *name)
{
  struct xml_input_state *state = ctx;

  printf ("%p->%s (%s)\n", state, __func__, name);
  if (xmlStrcmp (name, BAD_CAST "token") == 0)
    {
      pt_node *token = pt_token_new ( &state->token.location
                                    , (char const *)state->token.text
                                    , state->token.length
                                    , state->token.token
                                    );
      state->root = token;
      /*pt_node_unref (token);*/
    }
}

static void
xml_input_characters ( void *ctx
                     , const xmlChar *ch
                     , int len)
{
  struct xml_input_state *state = ctx;

  state->token.text = ch;
  state->token.length = len;
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
