/*
 * while statement
 */

/* constructor */
ast_node*     ast_while_statement_new           (ast_node *while_tok,
                                                 ast_node *open_bracket, ast_node *condition,
                                                 ast_node *close_bracket, ast_node *body);

/* accessors */
ast_node*     ast_while_statement_while         (ast_node const *self);
ast_node*     ast_while_statement_open_bracket  (ast_node const *self);
ast_node*     ast_while_statement_condition     (ast_node const *self);
ast_node*     ast_while_statement_close_bracket (ast_node const *self);
ast_node*     ast_while_statement_body          (ast_node const *self);
