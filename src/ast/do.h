struct ast_node_do_statement
{
  ast_node base;

  ast_node *do_tok;
  ast_node *body;
  ast_node *while_tok;
  ast_node *open_bracket;
  ast_node *condition;
  ast_node *close_bracket;
  ast_node *semicolon;
};

extern struct ast_vtbl const ast_do_statement_vtbl;

void ast_do_statement_construct (struct ast_node_do_statement *self,
                                 ast_node *do_tok, ast_node *body, ast_node *while_tok,
                                 ast_node *open_bracket, ast_node *condition,
                                 ast_node *close_bracket, ast_node *semicolon);
