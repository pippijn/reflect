/*
 * token
 */

/* constructor */
ast_node*               ast_token_new           (struct location const* loc,
                                                 char const* text,
                                                 size_t length, int token);

/* accessors */
char const*             ast_token_text          (ast_node const* self);
int                     ast_token_token         (ast_node const* self);
