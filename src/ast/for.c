#include "internal.h"

/* type of *self */

typedef struct ast_node_for_statement self_type;


/* vtable */

static fn_destruct ast_for_statement_destruct;
static fn_print ast_for_statement_print;


struct ast_vtbl ast_for_statement_vtbl = {
  ast_for_statement_destruct,
  ast_for_statement_print,
};


/* public */

ast_node*
ast_for_statement_new (struct location const* loc, struct ast_node_expression initializer,
                       struct ast_node_expression condition, struct ast_node_expression increment,
                       struct ast_node_statement body)
{
  struct ast_node_for_statement *self = malloc (sizeof self);

  ast_node_construct (&self->base, &ast_for_statement_vtbl, loc);

  self->initializer = initializer;
  self->condition   = condition;
  self->increment   = increment;
  self->body        = body;

  return &self->base;
}


/* accessors */

struct ast_node_expression
ast_for_statement_initializer(ast_node const *object)
{
  self_type const* self = (self_type const*)object;

  return self->initializer;
}

/* TODO insert missing ones */



/* virtual */

static void
ast_for_statement_destruct (ast_node* object)
{
  self_type* self = (self_type*)object;

  ast_node_destruct (&self->base);

  /* do we do free them here? */
  /*
  free (self->initializer);
  free (self->condition);
  free (self->increment);
  free (self->body);
  */
}

static void
ast_for_statement_print (ast_node const* object, FILE* fh)
{
  self_type const* self = (self_type const*)object;

  fputs ("for (", fh);
  ast_expression_print(self->initializer);
  fputs ("; ", fh);
  ast_expression_print(self->condition);
  fputs ("; ", fh);
  ast_expression_print(self->increment);
  fputs (") ", fh);
  ast_expression_print(self->body);
}
