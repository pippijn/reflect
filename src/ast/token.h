struct ast_node_token
{
  ast_node base;

  char* text;
  int token;
};

extern struct ast_vtbl const ast_token_vtbl;
