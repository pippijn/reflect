static void ast_node_construct (ast_node* self, struct location const* loc);


typedef void fn_print (ast_node const* self);

struct ast_vtbl
{
  fn_print* print;
};


struct ast_node
{
  struct ast_vtbl* vtbl;
  struct location location;
};
