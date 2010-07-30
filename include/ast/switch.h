/*
 * 
 */

/* constructor */
ast_node*       ast_switch_statement_new           (ast_node *switch_tok, ast_node *open_bracket,
                                                    ast_node *expr, ast_node *close_bracket,
                                                    ast_node *body);

/* accessors */
ast_node*       ast_switch_statement_switch        (ast_node const *self);
ast_node*       ast_switch_statement_open_bracket  (ast_node const *self);
ast_node*       ast_switch_statement_expr          (ast_node const *self);
ast_node*       ast_switch_statement_close_bracket (ast_node const *self);
ast_node*       ast_switch_statement_body          (ast_node const *self);
