#include <stack/impl_array.h>
#include <stack.h>

#include <pt.h>
#include <pt/visitor/impl.h>

#include "token_refinc.h"

typedef struct token_refinc self_type;

static void
token_refinc_visit_token (visitor_type *object, node_type const *node)
{
  SELF ();
  size_t i;

  for (i = 0; i < stack_size (self->tokens); i++)
    if ((node_type const *)stack_get (self->tokens, i) == node)
      pt_node_ref ((node_type *)node);
}

static vtbl_type token_refinc_vtbl = {
  {
    "token_refinc",
    sizeof (self_type)
  },
  token_refinc_visit_token
};


void
token_refinc_construct (self_type *self, stack *tokens)
{
  assert (self != NULL);

  pt_visitor_construct (&self->base, &token_refinc_vtbl);

  self->tokens = tokens;
}

void
token_refinc_destruct (self_type *self)
{
  assert (self != NULL);
}
