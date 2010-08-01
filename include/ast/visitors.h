#include <ast.h>

ast_visitor *ast_print_visitor_new (FILE *fh);
void ast_print_visitor_delete (ast_visitor *fh);

ast_visitor *ast_store_visitor_new (FILE *fh);
void ast_store_visitor_delete (ast_visitor *fh);
