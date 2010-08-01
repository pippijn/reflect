#include <pt.h>

pt_visitor *pt_print_visitor_new (FILE *fh);
void pt_print_visitor_delete (pt_visitor *fh);

pt_visitor *pt_store_visitor_new (FILE *fh);
void pt_store_visitor_delete (pt_visitor *fh);
