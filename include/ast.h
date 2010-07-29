#pragma once

#include <location.h>

typedef struct ast_node ast_node;

void                    ast_node_delete         (ast_node* self);
struct location const*  ast_node_location       (ast_node const* self);


ast_node*               ast_token_new           (struct location const* loc,
                                                 char const* text,
                                                 size_t length, int token);
char const*             ast_token_text          (ast_node* self);
int                     ast_token_token         (ast_node* self);
