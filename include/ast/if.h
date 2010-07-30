/*
 * 
 */

/* constructor */
ast_node*       ast_if_statement_new           (ast_node *if_tok, ast_node *open_bracket,
                                                ast_node *condition, ast_node *close_bracket,
                                                ast_node *if_body, ast_node *else_tok,
                                                ast_node *else_body);

/* accessors */
ast_node*       ast_if_statement_if            (ast_node const *self);
ast_node*       ast_if_statement_open_bracket  (ast_node const *self);
ast_node*       ast_if_statement_condition     (ast_node const *self);
ast_node*       ast_if_statement_close_bracket (ast_node const *self);
ast_node*       ast_if_statement_if_body       (ast_node const *self);
ast_node*       ast_if_statement_else          (ast_node const *self);
ast_node*       ast_if_statement_else_body     (ast_node const *self);
