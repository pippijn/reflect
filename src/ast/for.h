struct ast_node_for_statement
{
  ast_node base;

  ast_node* for_tok;
  ast_node* open_bracket;
  ast_node* initializer;
  ast_node* condition;
  ast_node* increment;
  ast_node* close_bracket;
  ast_node* body;
};


extern struct ast_vtbl const ast_for_statement_vtbl;


void ast_for_statement_construct (struct ast_node_for_statement* self,
                                  ast_node *for_tok, ast_node *open_bracket,
                                  ast_node *initializer, ast_node *condition,
                                  ast_node *increment, ast_node *close_bracket,
                                  ast_node *body);
