#include <libxml/parser.h>

#include <xml_input.h>

#include "input_state.h"

extern xmlSAXHandler xml_input_handler;

static pt_node *
xml_input (char const *filename)
{
  struct xml_input_state state = XML_INPUT_STATE_NULL;

  if (xmlSAXUserParseFile (&xml_input_handler, &state, filename) < 0)
    {
      pt_node_unref_ornull (state.root);
      return NULL;
    }
  else
    return state.root;
}


pt_node *
test_xml_parse (char const *file)
{
  return xml_input (file);
}
