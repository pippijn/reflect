struct ast_node_if_statement
{
  ast_node base;

  ast_node *if_tok;
  ast_node *open_bracket;
  ast_node *condition;
  ast_node *close_bracket;
  ast_node *if_body;
  ast_node *else_tok;
  ast_node *else_body;
};


extern struct ast_vtbl const ast_if_statement_vtbl;


void ast_if_statement_construct (struct ast_node_if_statement *self, ast_node *if_tok,
                                 ast_node *open_bracket, ast_node *condition,
                                 ast_node *close_bracket, ast_node *if_body,
                                 ast_node *else_tok, ast_node *else_body);
