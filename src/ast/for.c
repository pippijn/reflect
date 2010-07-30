#include "internal.h"

/* type of *self */

typedef struct ast_node_for_statement self_type;


/* vtable */

static fn_print ast_for_statement_print;


static struct ast_vtbl const* const vtbl = &ast_for_statement_vtbl;
struct ast_vtbl const ast_for_statement_vtbl = {
  &ast_node_vtbl,
  AST_FOR_STATEMENT,
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

  assert (ast_kind_is (for_tok, AST_TOKEN));
  assert (ast_kind_is (open_bracket, AST_TOKEN));
  assert (initializer != NULL);
  assert (condition != NULL);
  /*assert (increment != NULL);*/
  assert (ast_kind_is (close_bracket, AST_TOKEN));
  assert (body != NULL);

  start = ast_node_location (for_tok);
  end   = ast_node_location (body);

  loc.first_line = start->first_line;
  loc.first_column = start->first_column;
  loc.last_line = end->last_line;
  loc.last_column = end->last_column;

  self = NEW_SELF (&loc);

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

ast_node*
ast_for_statement_for (ast_node const* object)
{
  CONST_SELF ();

  return self->for_tok;
}

ast_node*
ast_for_statement_open_bracket (ast_node const* object)
{
  CONST_SELF ();

  return self->open_bracket;
}

ast_node*
ast_for_statement_initializer (ast_node const* object)
{
  CONST_SELF ();

  return self->initializer;
}

ast_node*
ast_for_statement_condition (ast_node const* object)
{
  CONST_SELF ();

  return self->condition;
}

ast_node*
ast_for_statement_increment (ast_node const* object)
{
  CONST_SELF ();

  return self->increment;
}

ast_node*
ast_for_statement_close_bracket (ast_node const* object)
{
  CONST_SELF ();

  return self->close_bracket;
}

ast_node*
ast_for_statement_body (ast_node const* object)
{
  CONST_SELF ();

  return self->body;
}


/* virtual */

static void
ast_for_statement_print (ast_node const* object, FILE* fh)
{
  CONST_SELF ();

  ast_node_print (self->for_tok, fh);
  ast_node_print (self->open_bracket, fh);
  ast_node_print (self->initializer, fh);
  ast_node_print (self->condition, fh);
  if (self->increment)
    ast_node_print (self->increment, fh);
  ast_node_print (self->close_bracket, fh);
  ast_node_print (self->body, fh);
}
