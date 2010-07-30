#include "internal.h"

/* type of self */

typedef struct ast_node_while_statement self_type;


/* vtable */

#if 0
static fn_destruct ast_while_statement_destruct;
#endif
static fn_print ast_while_statement_print;

static struct ast_vtbl const* const vtbl = &ast_while_statement_vtbl; /* <- Was genau macht das? */
struct ast_vtbl const ast_while_statement_vtbl = {
  {
     &ast_node_vtbl,
     "while_statement",
     AST_WHILE_STATEMENT,
  },
#if 0
  ast_while_statement_destruct,
#else
  ast_node_destruct,
#endif
  ast_while_statement_print,
};


/* internal */

void
ast_while_statement_construct (struct ast_node_while_statement *self,
                               ast_node *while_tok, ast_node *open_bracket,
                               ast_node *condition, ast_node *close_bracket,
                               ast_node *body)
{
  struct location loc;

  assert (ast_kind_is (while_tok, AST_TOKEN));
  assert (ast_kind_is (open_bracket, AST_TOKEN));
  assert (condition != NULL);
  assert (ast_kind_is (close_bracket, AST_TOKEN));
  assert (body != NULL);

  COMPUTE_LOC (while_tok, body);
  BASE_CTOR (node, &loc);

  self->while_tok     = while_tok;
  self->open_bracket  = open_bracket;
  self->condition     = condition;
  self->close_bracket = close_bracket;
  self->body          = body;
}

/* public */

ast_node*
ast_while_statement_new (ast_node *while_tok, ast_node *open_bracket,
                         ast_node *condition, ast_node *close_bracket,
                         ast_node *body)
{
  return NEW (while_statement, while_tok, open_bracket, condition,
              close_bracket, body);
}

/* accessors */

ast_node*
ast_while_statement_while (ast_node const *object)
{
  CONST_SELF ();

  return self->while_tok;
}

ACCESSOR (while_statement, open_bracket)
ACCESSOR (while_statement, condition)
ACCESSOR (while_statement, close_bracket)
ACCESSOR (while_statement, body)

/* virtual */

void
ast_while_statement_print (ast_node const *object, FILE *fh)
{
  CONST_SELF ();

  ast_node_print (self->while_tok, fh);
  ast_node_print (self->open_bracket, fh);
  ast_node_print (self->condition, fh);
  ast_node_print (self->close_bracket, fh);
  ast_node_print (self->body, fh);
}
