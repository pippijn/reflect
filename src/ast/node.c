#include "internal.h"

/*
 * public
 */

/* destructor */

void
ast_node_delete (ast_node* self)
{
  assert (self != NULL);
  assert (self->vtbl != NULL);

  self->vtbl->destruct (self);

  free (self);
}


/* accessors */

struct location const*
ast_node_location (ast_node const* self)
{
  assert (self != NULL);
  return &self->location;
}


/* methods */

void
ast_node_print (ast_node const* self, FILE* fh)
{
  assert (self != NULL);
  self->vtbl->print (self, fh);
}



/*
 * type checking
 */

bool
ast_kind_is (ast_node const* object, enum ast_kind kind)
{
  return object->kind == kind;
}

ast_node*
ast_cast_mutable (ast_node* object, enum ast_kind kind)
{
  assert (ast_kind_is (object, kind));
  return ast_kind_is (object, kind) ? object : NULL;
}

ast_node const*
ast_cast_const (ast_node const* object, enum ast_kind kind)
{
  assert (ast_kind_is (object, kind));
  return ast_kind_is (object, kind) ? object : NULL;
}



/*
 * protected
 */

void
ast_node_construct (ast_node* self, struct ast_vtbl const* vtbl, enum ast_kind kind, struct location const* loc)
{
  assert (self != NULL);
  assert (vtbl != NULL);
  assert (loc != NULL);

  self->vtbl = vtbl;
  self->kind = kind;
  self->location = *loc;
}

void
ast_node_destruct (ast_node* self)
{
}
