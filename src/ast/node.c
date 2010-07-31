#include "internal.h"

/* type of *self */

typedef struct ast_node_token self_type;


/* vtable */

struct ast_vtbl const ast_node_vtbl = {
  {
    NULL,
    "node",
    AST_NODE,
  },
  ast_node_destruct,
  (fn_print *)pure_virtual,
};


/*
 * public
 */

/* destructor */

void
ast_node_delete (ast_node *self)
{
  assert (self != NULL);
  assert (self->vtbl != NULL);

  self->vtbl->destruct (self);

  free (self);
}


/* accessors */

struct location const *
ast_node_location (ast_node const *self)
{
  assert (self != NULL);
  return &self->location;
}


/* methods */

void
ast_node_print (ast_node const *self, FILE *fh)
{
  assert (self != NULL);
  assert (self->vtbl != NULL);

  self->vtbl->print (self, fh);
}



/*
 * type checking
 */

void
pure_virtual (void)
{
  fputs ("pure virtual function called\n", stderr);
  abort ();
}

bool
ast_kind_is (ast_node const *object, enum ast_kind kind)
{
  if (object == NULL)
    return false;
  assert (object->vtbl != NULL);
  return object->vtbl->ti.kind == kind;
}

bool
ast_kind_derived (ast_node const *object, enum ast_kind kind)
{
  struct ast_vtbl const *vtbl = NULL;

  if (object == NULL)
    return false;

  assert (object->vtbl != NULL);

  for (vtbl = object->vtbl; vtbl; vtbl = vtbl->ti.base)
    if (vtbl->ti.kind == kind)
      return true;

  return false;
}

ast_node *
ast_cast_mutable (ast_node *object, enum ast_kind kind)
{
  assert (ast_kind_derived (object, kind));
  return ast_kind_derived (object, kind) ? object : NULL;
}

ast_node const *
ast_cast_const (ast_node const *object, enum ast_kind kind)
{
  assert (ast_kind_derived (object, kind));
  return ast_kind_derived (object, kind) ? object : NULL;
}



/*
 * protected
 */

void
ast_node_construct (ast_node *self, struct ast_vtbl const *vtbl, struct location const *loc)
{
  assert (self != NULL);
  assert (vtbl != NULL);
  assert (loc != NULL);

  self->vtbl = vtbl;
  self->location = *loc;
}

void
ast_node_destruct (ast_node *self)
{
  assert (self != NULL);
  assert (self->vtbl != NULL);
}
