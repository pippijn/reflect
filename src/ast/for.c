#include "internal.h"

/* type of *self */

typedef struct ast_node_for_statement self_type;


/* vtable */

#if 0
static fn_destruct ast_for_statement_destruct;
#endif
static fn_print ast_for_statement_print;

static struct ast_vtbl const* const vtbl = &ast_for_statement_vtbl;
struct ast_vtbl const ast_for_statement_vtbl = {
  {
    &ast_node_vtbl,
    "for_statement",
    AST_FOR_STATEMENT,
  },
#if 0
  ast_for_statement_destruct,
#else
  ast_node_destruct,
#endif
  ast_for_statement_print,
};


/* internal */

void
ast_for_statement_construct (self_type* self, ast_node *for_tok,
                             ast_node *open_bracket, ast_node *initializer,
                             ast_node *condition, ast_node *increment,
                             ast_node *close_bracket, ast_node *body)
{
  struct location loc;

  assert (ast_kind_is (for_tok, AST_TOKEN));
  assert (ast_kind_is (open_bracket, AST_TOKEN));
  assert (initializer != NULL);
  assert (condition != NULL);
  /*assert (increment != NULL);*/
  assert (ast_kind_is (close_bracket, AST_TOKEN));
  assert (body != NULL);

  COMPUTE_LOC (for_tok, body);
  BASE_CTOR (node, &loc);

  self->for_tok       = for_tok;
  self->open_bracket  = open_bracket;
  self->initializer   = initializer;
  self->condition     = condition;
  self->increment     = increment;
  self->close_bracket = close_bracket;
  self->body          = body;
}


/* public */

ast_node*
ast_for_statement_new (ast_node *for_tok,
                       ast_node *open_bracket, ast_node *initializer,
		       ast_node *condition, ast_node *increment,
                       ast_node *close_bracket, ast_node *body)
{
  return NEW (for_statement, for_tok, open_bracket, initializer,
              condition, increment, close_bracket, body);
}


/* accessors */

ast_node*
ast_for_statement_for (ast_node const* object)
{
  CONST_SELF ();

  return self->for_tok;
}

ACCESSOR (for_statement, open_bracket);
ACCESSOR (for_statement, initializer);
ACCESSOR (for_statement, condition);
ACCESSOR (for_statement, increment);
ACCESSOR (for_statement, close_bracket);
ACCESSOR (for_statement, body);


/* virtual */

void
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
