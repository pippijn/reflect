#include "internal.h"

/* type of self */

typedef struct ast_node_if_statement self_type;


/* vtable */

#if 0
static fn_destruct ast_if_statement_destruct;
#endif
static fn_print ast_if_statement_print;

static struct ast_vtbl const* const vtbl = &ast_if_statement_vtbl;
struct ast_vtbl const ast_if_statement_vtbl = {
  {
    &ast_node_vtbl,
    "if_statement",
    AST_IF_STATEMENT,
  },
#if 0
  ast_if_statement_destruct,
#else
  ast_node_destruct,
#endif
  ast_if_statement_print,
};


/* internal */

void
ast_if_statement_construct (self_type* self, ast_node *if_tok, ast_node *open_bracket,
                            ast_node *condition, ast_node *close_bracket, ast_node *if_body,
                            ast_node *else_tok, ast_node *else_body)
{
  struct location loc;

  assert (ast_kind_is (if_tok, AST_TOKEN));
  assert (ast_kind_is (open_bracket, AST_TOKEN));
  assert (condition != NULL);
  assert (ast_kind_is (close_bracket, AST_TOKEN));
  assert (if_body != NULL);

  /* neither can live without the other */
  if (else_tok != NULL)
    assert (else_body != NULL);
  if (else_body != NULL)
    assert (else_tok != NULL);

  /* this may require braces when the macro changes */
  if (else_tok == NULL)
    COMPUTE_LOC (if_tok, if_body);
  else
    COMPUTE_LOC (if_tok, else_body);

  BASE_CTOR (node, &loc);

  self->if_tok        = if_tok;
  self->open_bracket  = open_bracket;
  self->condition     = condition;
  self->close_bracket = close_bracket;
  self->if_body       = if_body;
  self->else_tok      = else_tok;
  self->else_body     = else_body;
}


/* public */

ast_node*
ast_if_statement_new (ast_node *if_tok, ast_node *open_bracket, ast_node *condition,
                      ast_node *close_bracket, ast_node *if_body, ast_node *else_tok,
                      ast_node *else_body)
{
  return NEW (if_statement, if_tok, open_bracket, condition, close_bracket,
              if_body, else_tok, else_body);
}


/* accessors */

ast_node*
ast_if_statement_if (ast_node const* object)
{
  CONST_SELF ();

  return self->if_tok;
}

ACCESSOR (if_statement, open_bracket);
ACCESSOR (if_statement, condition);
ACCESSOR (if_statement, close_bracket);
ACCESSOR (if_statement, if_body);

ast_node*
ast_if_statement_else (ast_node const* object)
{
  CONST_SELF ();

  return self->else_tok;
}

ACCESSOR (if_statement, else_body);


/* virtual */

void
ast_if_statement_print (ast_node const* object, FILE* fh)
{
  CONST_SELF ();

  ast_node_print (self->if_tok, fh);
  ast_node_print (self->open_bracket, fh);
  ast_node_print (self->condition, fh);
  ast_node_print (self->close_bracket, fh);
  ast_node_print (self->if_body, fh);
  ast_node_print (self->else_tok, fh);
  ast_node_print (self->else_body, fh);
}
