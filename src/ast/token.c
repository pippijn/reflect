#include "internal.h"

/* type of *self */

typedef struct ast_node_token self_type;


/* vtable */

static fn_destruct ast_token_destruct;
static fn_print ast_token_print;


static struct ast_vtbl const* const vtbl = &ast_token_vtbl;
struct ast_vtbl const ast_token_vtbl = {
  &ast_node_vtbl,
  AST_TOKEN,
  ast_token_destruct,
  ast_token_print,
};


/* public */

ast_node*
ast_token_new (struct location const* loc, char const* text, size_t length, int token)
{
  self_type* self = NULL;

  assert (loc != NULL);
  assert (text != NULL);
  assert (length > 0);

  /* base constructor */
  NEW_SELF (loc);

  /* initialise our own data */
  self->text = strndup (text, length);
  self->token = token;

  assert (self->text != NULL);

  return &self->base;
}


/* accessors */

char const*
ast_token_text (ast_node const* object)
{
  CONST_SELF ();

  return self->text;
}

int
ast_token_token (ast_node const* object)
{
  CONST_SELF ();

  return self->token;
}


/* virtual */

static void
ast_token_destruct (ast_node* object)
{
  SELF ();

  assert (self->text);

  /* destroy our own data */
  free (self->text);

  /* base destructor */
  BASE_DESTRUCT ();
}

static void
ast_token_print (ast_node const* object, FILE* fh)
{
  CONST_SELF ();

  fprintf (fh, "token { \"%s\" }\n", self->text);
}
