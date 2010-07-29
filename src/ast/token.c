#include "internal.h"

/* type of *self */

typedef struct ast_node_token self_type;


/* vtable */

static fn_destruct ast_token_destruct;
static fn_print ast_token_print;


struct ast_vtbl ast_token_vtbl = {
  ast_token_destruct,
  ast_token_print,
};


/* public */

ast_node*
ast_token_new (struct location const* loc, char const* text, size_t length, int token)
{
  struct ast_node_token* self = malloc (sizeof *self);

  ast_node_construct (&self->base, &ast_token_vtbl, loc);

  self->text = strndup (text, length);
  self->token = token;

  return &self->base;
}


/* virtual */

static void
ast_token_destruct (ast_node* object)
{
  self_type* self = (self_type*)object;

  ast_node_destruct (&self->base);

  free (self->text);
}

static void
ast_token_print (FILE* fh, ast_node const* object)
{
  self_type const* self = (self_type const*)object;

  fprintf (fh, "token { %s }", self->text);
}
