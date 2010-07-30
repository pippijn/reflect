struct ast_node_switch_statement
{
  ast_node base;

  ast_node *switch_tok;
  ast_node *open_bracket;
  ast_node *expr;
  ast_node *close_bracket;
  ast_node *body;
};


extern struct ast_vtbl const ast_switch_statement_vtbl;


void ast_switch_statement_construct (struct ast_node_switch_statement *self,
                                     ast_node *switch_tok, ast_node *open_bracket,
                                     ast_node *expr, ast_node *close_bracket,
                                     ast_node *body);
