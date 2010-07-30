struct ast_node_while_statement
{
  ast_node base;

  ast_node *while_tok;
  ast_node *open_bracket;
  ast_node *condition;
  ast_node *close_bracket;
  ast_node *body;
};

extern struct ast_vtbl const ast_while_statement_vtbl;

void ast_while_statement_construct (struct ast_node_while_statement *self,
                                    ast_node *while_tok, ast_node *open_bracket,
                                    ast_node *condition, ast_node *close_bracket,
                                    ast_node *body);
