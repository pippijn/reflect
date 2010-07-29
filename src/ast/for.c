#include "internal.h"

/* type of *self */

typedef struct ast_node_for_statement self_type;


/* vtable */

static fn_print ast_for_statement_print;


struct ast_vtbl ast_for_statement_vtbl = {
  ast_node_destruct,
  ast_for_statement_print,
};


/* public */

ast_node*
ast_for_statement_new (struct ast_node *for_tok,
                           struct ast_node *open_bracket, struct ast_node *initializer,
		           struct ast_node *condition, struct ast_node *increment,
                           struct ast_node *close_bracket, struct ast_node *body)
{
  self_type *self = malloc (sizeof (self_type*));
  struct location *loc = malloc (sizeof (struct location*));
  struct location const *start;
  struct location const *end;

  start = ast_node_location(for_tok);
  end   = ast_node_location(body);

  loc->first_line = start->first_line;
  loc->first_column = start->first_column;
  loc->last_line = end->last_line;
  loc->last_column = end->last_column;

  ast_node_construct (&self->base, &ast_for_statement_vtbl, AST_FOR_STATEMENT, loc);

  self->for_tok       = for_tok;
  self->open_bracket  = open_bracket;
  self->initializer   = initializer;
  self->condition     = condition;
  self->increment     = increment;
  self->close_bracket = close_bracket;
  self->body          = body;

  return &self->base;
}


/* accessors */

struct ast_node *
ast_for_statement_for (ast_node *object)
{
  self_type const* self = (self_type const *)object;

  return self->for_tok;
}

struct ast_node *
ast_for_statement_open_bracket (ast_node const *object)
{

  self_type const* self = (self_type const *)object;

  return self->open_bracket;
}

struct ast_node *
ast_for_statement_initializer (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->initializer;
}

struct ast_node *
ast_for_statement_condition (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->condition;
}

struct ast_node *
ast_for_statement_increment (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->increment;
}

struct ast_node *
ast_for_statement_close_bracket (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->close_bracket;
}

struct ast_node *
ast_for_statement_body (ast_node const *object)
{
  self_type const* self = (self_type const *)object;

  return self->body;
}


/* virtual */

static void
ast_for_statement_print (ast_node const* object, FILE* fh)
{
  self_type const* self = (self_type const*)object;

  ast_token_print (self->for_tok);
  ast_token_print (self->open_bracket);
  ast_expression_statement_print (self->initializer);
  ast_expression_statement_print (self->condition);
  if (self->increment)
    ast_expression_print (self->increment);
  ast_token_print (self->close_bracket);
  ast_statement_print (self->body);
}
