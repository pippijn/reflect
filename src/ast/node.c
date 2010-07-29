#include "internal.h"

/*
 * public
 */

/* destructor */

void
ast_node_delete (ast_node* self)
{
  self->vtbl->destruct (self);

  free (self);
}


/* accessors */

struct location const*
ast_node_location (ast_node const* self)
{
  return &self->location;
}


/* methods */

void
ast_node_print (ast_node const* self, FILE* fh)
{
  self->vtbl->print (self, fh);
}



/*
 * protected
 */

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
