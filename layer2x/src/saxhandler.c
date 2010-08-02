#include <libxml/parser.h>

#include "input_state.h"


static void
xml_input_startDocument (void *ctx)
{
  struct xml_input_state *state = ctx;
  assert (state->node == NULL);
}

static void
xml_input_endDocument (void *ctx)
{
  struct xml_input_state *state = ctx;
  if (0)
  assert (state->node != NULL);
}

static void
xml_input_startElement ( void *ctx
                       , const xmlChar *name
                       , const xmlChar **atts)
{
  xmlChar const **it;
  struct xml_input_state *state = ctx;
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

  fprintf (stdout, "%p: warning: ", state->node);
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

  fprintf (stdout, "%p: error: ", state->node);
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
  NULL,
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
