#include <pt.h>

typedef struct stack stack;

struct xml_input_state
{
  pt_node *root;
  struct stack* stack;
  struct
  {
    struct location location;
    xmlChar const *text;
    int length;
    int token;
  } token;
};

#define XML_INPUT_STATE_NULL    \
  {                             \
    NULL,                       \
    NULL,                       \
    {                           \
      { 0, 0, 0, 0 },           \
      NULL, 0, 0                \
    }                           \
  }
