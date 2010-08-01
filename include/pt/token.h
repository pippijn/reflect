/*
 * token
 */

/* constructor */
pt_node                *pt_token_new           ( struct location const *loc
                                               , char const *text
                                               , size_t length
                                               , int token);

/* accessors */
char const             *pt_token_text          (pt_node const *self);
int                     pt_token_token         (pt_node const *self);
