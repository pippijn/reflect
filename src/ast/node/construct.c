static void
ast_node_construct (ast_node* self, struct location const* loc)
{
  self->location = *loc;
}
