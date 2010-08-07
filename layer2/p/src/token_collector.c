#include <stack/impl_array.h>
#include <stack.h>

#include <pt.h>
#include <pt/visitor/impl.h>

#include "token_collector.h"


typedef struct token_collector self_type;

static void
token_collector_visit_token (visitor_type *object, node_type const *node)
{
  SELF ();

  stack_push (self->tokens, (node_type *)node);
}

static vtbl_type token_collector_vtbl = {
  {
    "token_collector",
    sizeof (self_type)
  },
  token_collector_visit_token
};


void
token_collector_construct (self_type *self)
{
  assert (self != NULL);

  pt_visitor_construct (&self->base, &token_collector_vtbl);

  self->tokens = stack_new ();
}

void
token_collector_destruct (self_type *self)
{
  assert (self != NULL);

  stack_delete (self->tokens);
}
