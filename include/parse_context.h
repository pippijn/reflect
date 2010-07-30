#pragma once

typedef struct parse_context parse_context;

parse_context* parse_context_new (void);
void parse_context_delete (parse_context* self);

void* parse_context_scanner (parse_context* self);
