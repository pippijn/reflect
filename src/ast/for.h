struct ast_node_for_statement
{
  struct ast_node base;

  struct ast_node *for_tok;
  struct ast_node *open_bracket;
  struct ast_node *initializer;
  struct ast_node *condition;
  struct ast_node *increment;
  struct ast_node *close_bracket;
  struct ast_node *body;
};
