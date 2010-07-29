typedef void fn_destruct (ast_node* node);
typedef void fn_print (ast_node const* node, FILE* fh);

struct ast_vtbl
{
  fn_destruct* destruct;
  fn_print* print;
};


struct ast_node
{
  struct ast_vtbl const* vtbl;
  struct location location;
};


void ast_node_construct (ast_node* self, struct ast_vtbl const* vtbl, struct location const* loc);

fn_destruct ast_node_destruct;
