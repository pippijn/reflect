#pragma once

#include <ast.h>

typedef struct parse_context parse_context;

parse_context *parse_context_new (void);
void parse_context_delete (parse_context *self);


void *parse_context_scanner (parse_context const *self);

ast_node *parse_context_unit (parse_context const *self);
void parse_context_unit_set (parse_context *self, ast_node *unit);
