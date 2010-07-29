#include "internal.h"

/* type of *self */

typedef struct ast_node_for_statement self_type;


/* vtable */

static fn_print ast_for_statement_print;


struct ast_vtbl vtbl = {
  ast_node_destruct,
  ast_for_statement_print,
};


/* public */

ast_node*
ast_for_statement_new (ast_node *for_tok,
                       ast_node *open_bracket, ast_node *initializer,
		       ast_node *condition, ast_node *increment,
                       ast_node *close_bracket, ast_node *body)
{
  self_type *self = NULL;
  struct location loc;
  struct location const *start;
  struct location const *end;

  start = ast_node_location(for_tok);
  end   = ast_node_location(body);

  loc.first_line = start->first_line;
  loc.first_column = start->first_column;
  loc.last_line = end->last_line;
  loc.last_column = end->last_column;

  NEW_SELF (AST_FOR_STATEMENT, &loc);

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
  CONST_SELF (AST_FOR_STATEMENT);

  return self->for_tok;
}

struct ast_node *
ast_for_statement_open_bracket (ast_node const *object)
{
  CONST_SELF (AST_FOR_STATEMENT);

  return self->open_bracket;
}

struct ast_node *
ast_for_statement_initializer (ast_node const *object)
{
  CONST_SELF (AST_FOR_STATEMENT);

  return self->initializer;
}

struct ast_node *
ast_for_statement_condition (ast_node const *object)
{
  CONST_SELF (AST_FOR_STATEMENT);

  return self->condition;
}

struct ast_node *
ast_for_statement_increment (ast_node const *object)
{
  CONST_SELF (AST_FOR_STATEMENT);

  return self->increment;
}

struct ast_node *
ast_for_statement_close_bracket (ast_node const *object)
{
  CONST_SELF (AST_FOR_STATEMENT);

  return self->close_bracket;
}

struct ast_node *
ast_for_statement_body (ast_node const *object)
{
  CONST_SELF (AST_FOR_STATEMENT);

  return self->body;
}


/* virtual */

static void
ast_for_statement_print (ast_node const* object, FILE* fh)
{
  CONST_SELF (AST_FOR_STATEMENT);

  ast_node_print (self->for_tok, fh);
  ast_node_print (self->open_bracket, fh);
  ast_node_print (self->initializer, fh);
  ast_node_print (self->condition, fh);
  if (self->increment)
    ast_node_print (self->increment, fh);
  ast_node_print (self->close_bracket, fh);
  ast_node_print (self->body, fh);
}
