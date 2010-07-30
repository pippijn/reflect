#include "internal.h"

/* type of self */

typedef struct ast_node_switch_statement self_type;


/* vtable */

#if 0
static fn_destruct ast_switch_statement_destruct;
#endif
static fn_print ast_switch_statement_print;

static struct ast_vtbl const* const vtbl = &ast_switch_statement_vtbl;
struct ast_vtbl const ast_switch_statement_vtbl = {
  {
    &ast_node_vtbl,
    "switch_statement",
    AST_SWITCH_STATEMENT,
  },
#if 0
  ast_switch_statement_destruct,
#else
  ast_node_destruct,
#endif
  ast_switch_statement_print,
};


/* internal */

void
ast_switch_statement_construct (self_type* self, ast_node *switch_tok, ast_node *open_bracket,
                                ast_node *expr, ast_node *close_bracket, ast_node *body)
{
  struct location loc;

  assert (ast_kind_is (switch_tok, AST_TOKEN));
  assert (ast_kind_is (open_bracket, AST_TOKEN));
  assert (expr != NULL);
  assert (ast_kind_is (close_bracket, AST_TOKEN));
  assert (body != NULL);

  COMPUTE_LOC (switch_tok, body);
  BASE_CTOR (node, &loc);

  self->switch_tok    = switch_tok;
  self->open_bracket  = open_bracket;
  self->expr          = expr;
  self->close_bracket = close_bracket;
  self->body          = body;
}


/* public */

ast_node*
ast_switch_statement_new (ast_node *switch_tok, ast_node *open_bracket,
                          ast_node *expr, ast_node *close_bracket,
                          ast_node *body)
{
  return NEW (switch_statement, switch_tok, open_bracket, expr,
              close_bracket, body);
}


/* accessors */

ast_node*
ast_switch_statement_switch (ast_node const* object)
{
  CONST_SELF ();

  return self->switch_tok;
}

  ACCESSOR (switch_statement, open_bracket);
  ACCESSOR (switch_statement, expr);
  ACCESSOR (switch_statement, close_bracket);
  ACCESSOR (switch_statement, body);


/* virtual */

void
ast_switch_statement_print (ast_node const* object, FILE* fh)
{
  CONST_SELF ();

  ast_node_print (self->switch_tok, fh);
  ast_node_print (self->open_bracket, fh);
  ast_node_print (self->expr, fh);
  ast_node_print (self->close_bracket, fh);
  ast_node_print (self->body, fh);
}
