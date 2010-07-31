#include "internal.h"


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
