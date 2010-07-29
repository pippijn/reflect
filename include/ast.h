#pragma once

#include <location.h>

typedef struct ast_node ast_node;

ast_node* ast_new_token (struct location const* loc, int token);
