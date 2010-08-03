#include <libxml/parser.h>

#include <xml_input.h>

#include "input_state.h"

static pt_node *
xml_input (char const *filename)
{
  xmlSAXHandler handler = xml_input_handler;
  struct xml_input_state state = XML_INPUT_STATE_NULL;
  pt_node *node = NULL;

  xmlInitParser ();

  if (xmlSAXUserParseFile (&handler, &state, filename) < 0)
    assert (state.root == NULL);
  else
    node = state.root;

  xmlCleanupParser ();

  return node;
}


pt_node *
test_xml_parse (char const *file)
{
  return xml_input (file);
}
