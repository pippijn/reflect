#include "internal.h"

/* type of *self */

typedef struct ast_node_for_tok_statement self_type;


/* vtable */

static fn_print ast_for_tok_statement_print;


struct ast_vtbl ast_for_tok_statement_vtbl = {
  ast_node_destruct,
  ast_for_tok_statement_print,
};


/* public */

ast_node*
ast_for_tok_statement_new (struct location const* loc, struct ast_node *for,
                       struct ast_node *open_brace, struct ast_node *initializer,
		       struct ast_node *condition, struct ast_node *increment,
                       struct ast_node *close_brace, struct ast_node *body)
{
  self_type *self = malloc (sizeof *self_type);

  ast_node_construct (&self->base, &ast_for_tok_statement_vtbl, loc);

  self->for_tok         = for;
  self->open_brace  = open_brace;
  self->initializer = initializer;
  self->condition   = condition;
  self->increment   = increment;
  self->close_brace = close_brace;
  self->body        = body;

  ast_node_for_tok_statement_n
  return &self->base;
}


/* accessors */

struct ast_node *
ast_for_tok_statement_for (ast_node *object)
{
  self_type const* self = (self_type const *)object;

  return self->for_tok;
}

struct ast_node *
ast_for_tok_statement_open_brace (ast_node *object)
{

  self_type const* self = (self_type const *)object;

  return self->open_brace;
}

struct ast_node *
ast_for_tok_statement_initializer (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->initializer;
}

struct ast_node *
ast_for_tok_statement_condition (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->condition;
}

struct ast_node *
ast_for_tok_statement_increment (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->increment;
}

struct ast_node *
ast_for_tok_statement_close_brace (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->close_brace;
}

struct ast_node *
ast_for_tok_statement_body (ast_node *object)
{
  self_type const* self = (self_type const *)object;

  return self->body;
}


/* virtual */

static void
ast_for_tok_statement_print (ast_node const* object, FILE* fh)
{
  self_type const* self = (self_type const*)object;

  ast_token_print (self->for_tok);
  ast_token_print (self->open_brace);
  ast_expression_statement_print (self->initializer);
  ast_expression_statement_print (self->condition);
  if (self->increment)
    ast_expression_print (self->increment);
  ast_token_print (self->close_brace);
  ast_statement_print (self->body);
}
