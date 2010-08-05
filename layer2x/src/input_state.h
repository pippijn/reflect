#include <pt.h>

#include <cpparray_stack.h>
#include <cppstack.h>

enum state
{
  TOKEN,
  STRUCT,
  MEMBER
};

struct xml_input_state
{
  pt_node *root;
  array_stack *node_stack;
  stack *state_stack;
  struct
  {
    struct location location;
    struct
    {
      xmlChar *data;
      int length;
      int capacity;
    } text;
    int token;
  } token;
  int empty_child;
};

#define XML_INPUT_STATE_NULL    \
  {                             \
    NULL,                       \
    NULL,                       \
    NULL,                       \
    {                           \
      { 0, 0, 0, 0 },           \
      { NULL, 0, 0 },           \
      0                         \
    },                          \
    0                           \
  }

extern xmlSAXHandler const xml_input_handler;
