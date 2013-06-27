#define L_TREE pt

typedef pt_node node_type;
typedef pt_visitor visitor_type;
typedef struct pt_visitor_vtbl vtbl_type;

#define SELF() self_type *self = (self_type *)object
