ast_node*
ast_new_token (struct location const* loc, int token)
{
  struct ast_node_token* self = malloc (sizeof *self);

  ast_node_construct (&self->base, loc);

  self->token = token;

  return &self->base;
}
