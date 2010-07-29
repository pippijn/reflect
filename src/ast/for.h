struct ast_node_for_statement
{
  struct ast_node base;

  /* we do not care about the semicolons... or do we?
  struct ast_node_expression_statement initializer;
  struct ast_node_expression_statement check;
  */

  struct ast_node_expression initializer;
  struct ast_node_expression condition;
  struct ast_node_expression increment;
  struct ast_node_statement  body;
}
