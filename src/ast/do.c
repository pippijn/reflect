#include "internal.h"

/* type of self */
typedef struct ast_node_do_statement self_type;


/* vtable */

#if 0
static fn_destruct ast_do_statement_destruct;
#endif
static fn_print ast_do_statement_print;

static struct ast_vtbl const* const vtbl = &ast_do_statement_vtbl;
struct ast_vtbl const ast_do_statement_vtbl = {
  {
    &ast_node_vtbl,
    "do_statement",
    AST_DO_STATEMENT,
  },
#if 0
  ast_do_statement_destruct,
#else
  ast_node_destruct,
#endif
  ast_do_statement_print,
};


/* internal */

void
ast_do_statement_construct (struct ast_node_do_statement *self,
                            ast_node *do_tok, ast_node *body, ast_node *while_tok,
                            ast_node *open_bracket, ast_node *condition,
                            ast_node *close_bracket, ast_node *semicolon)
{
  struct location loc;

  assert (ast_kind_is (do_tok, AST_TOKEN));
  assert (body != NULL);
  assert (ast_kind_is (while_tok, AST_TOKEN));
  assert (ast_kind_is (open_bracket, AST_TOKEN));
  assert (condition != NULL);
  assert (ast_kind_is (close_bracket, AST_TOKEN));
  assert (ast_kind_is (semicolon, AST_TOKEN));

  COMPUTE_LOC (do_tok, semicolon);
  BASE_CTOR (node, &loc);

  self->do_tok        = do_tok;
  self->body          = body;
  self->while_tok     = while_tok;
  self->open_bracket  = open_bracket;
  self->condition     = condition;
  self->close_bracket = close_bracket;
  self->semicolon     = semicolon;
}


/* public */

ast_node *
ast_do_statement_new (ast_node *do_tok, ast_node *body, ast_node *while_tok,
                      ast_node *open_bracket, ast_node *condition,
                      ast_node *close_bracket, ast_node *semicolon)
{
  return NEW (do_statement, do_tok, body, while_tok, open_bracket, condition,
              close_bracket, semicolon);
}


/* accessors */

ast_node *
ast_do_statement_do (ast_node const *object)
{
  CONST_SELF ();

  return self->do_tok;
}

ACCESSOR (do_statement, body)

ast_node *
ast_do_statement_while (ast_node const *object)
{
  CONST_SELF ();

  return self->while_tok;
}

ACCESSOR (do_statement, open_bracket)
ACCESSOR (do_statement, condition)
ACCESSOR (do_statement, close_bracket)
ACCESSOR (do_statement, semicolon)


/* virtual */

void
ast_do_statement_print (ast_node const *object, FILE *fh)
{
  CONST_SELF ();

  ast_node_print (self->do_tok, fh);
  ast_node_print (self->body, fh);
  ast_node_print (self->while_tok, fh);
  ast_node_print (self->open_bracket, fh);
  ast_node_print (self->condition, fh);
  ast_node_print (self->close_bracket, fh);
  ast_node_print (self->semicolon, fh);
}
