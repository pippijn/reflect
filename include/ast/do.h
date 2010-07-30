/*
 * do statement
 */

/* constructor */
ast_node*     ast_do_statement_new              (ast_node *do_tok,
                                                 ast_node *body, ast_node *while_tok,
                                                 ast_node *open_bracket, ast_node *condition,
                                                 ast_node *close_bracket, ast_node *semicolon);

/* accessors */
ast_node*     ast_do_statement_do               (ast_node const *self);
ast_node*     ast_do_statement_body             (ast_node const *self);
ast_node*     ast_do_statement_while            (ast_node const *self);
ast_node*     ast_do_statement_open_bracket     (ast_node const *self);
ast_node*     ast_do_statement_condition        (ast_node const *self);
ast_node*     ast_do_statement_close_bracket    (ast_node const *self);
ast_node*     ast_do_statement_semicolon        (ast_node const *self);
