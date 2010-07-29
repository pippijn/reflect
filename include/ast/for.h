/*
 * for statement
 */

/* constructor */
ast_node*       ast_for_statement_new           (struct location const* loc, struct ast_node *for_tok,
                                                 struct ast_node *open_brace, struct ast_node *initializer,
		                                 struct ast_node *condition, struct ast_node *increment,
                                                 struct ast_node *close_brace, struct ast_node *body);

/* accessors */
ast_node*       ast_for_statement_for_tok       (ast_node const *self);
ast_node*       ast_for_statement_open_brace    (ast_node const *self);
ast_node*       ast_for_statement_initializer   (ast_node const *self);
ast_node*       ast_for_statement_condition     (ast_node const *self);
ast_node*       ast_for_statement_increment     (ast_node const *self);
ast_node*       ast_for_statement_close_brace   (ast_node const *self);
ast_node*       ast_for_statement_body          (ast_node const *self);
