#include "internal.h"

/* public */

void
ast_node_delete (ast_node* self)
{
  self->vtbl->destruct (self);

  free (self);
}

/* private */

void
ast_node_construct (ast_node* self, struct ast_vtbl const* vtbl, struct location const* loc)
{
  self->vtbl = vtbl;
  self->location = *loc;
}

void
ast_node_destruct (ast_node* self)
{
}
