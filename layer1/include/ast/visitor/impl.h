#define L_TREE ast

typedef ast_node node_type;
typedef ast_visitor visitor_type;
typedef struct ast_visitor_vtbl vtbl_type;

#define SELF() self_type *self = (self_type *)object
