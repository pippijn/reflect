#include "internal.h"

/* type of *self */

typedef struct ast_node_token self_type;


/* vtable */

struct ast_vtbl const ast_node_vtbl = {
  {
    NULL,
    "node",
    AST_NODE,
    sizeof (ast_node),
  },
  ast_node_destruct,
  (fn_print *)pure_virtual,
};


/*
 * public
 */

/* destructor */

static void
ast_node_delete (ast_node *self)
{
  assert (self != NULL);
  assert (self->vtbl != NULL);

  self->vtbl->destruct (self);

  sever (self, self->vtbl->ti.size);
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
 * protected
 */

void
ast_node_construct (ast_node *self, struct ast_vtbl const *vtbl, struct location const *loc)
{
  ast_node node = { vtbl, *loc, 1 };
  assert (self != NULL);
  assert (vtbl != NULL);
  assert (loc != NULL);

#if 0
  printf ("constructing %s: %p\n", vtbl->ti.name, self);
#endif

  memcpy (self, &node, sizeof node);
}

void
ast_node_destruct (ast_node *self)
{
  assert (self != NULL);
  assert (self->vtbl != NULL);
}

ast_node *
ast_node_ref (ast_node *self)
{
  assert (self != NULL);
  return ast_node_ref_ornull (self);
}

ast_node *
ast_node_ref_ornull (ast_node *self)
{
  if (self != NULL)
    {
#if 0
      printf ("++ref (%s) => %d\n", self->vtbl->ti.name, self->refcnt + 1);
#endif

      ++self->refcnt;
    }

  return self;
}

void
ast_node_unref (ast_node *self)
{
  assert (self != NULL);
  ast_node_unref_ornull (self);
}

void
ast_node_unref_ornull (ast_node *self)
{
  if (self != NULL)
    {
#if 0
      printf ("--ref (%s) => %d\n", self->vtbl->ti.name, self->refcnt - 1);
#endif

      if (--self->refcnt == 0)
        ast_node_delete (self);
    }
}
