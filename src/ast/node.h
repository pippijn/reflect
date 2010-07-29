typedef void fn_destruct (ast_node* node);
typedef void fn_print (ast_node const* node, FILE* fh);

struct ast_vtbl
{
  fn_destruct* destruct;
  fn_print* print;
};


enum ast_kind
{
  AST_TOKEN,
  AST_FOR_STATEMENT,
};


struct ast_node
{
  struct ast_vtbl const* vtbl;
  enum ast_kind kind;
  struct location location;
};


bool ast_kind_is (ast_node const* object, enum ast_kind kind);
ast_node* ast_cast_mutable (ast_node* object, enum ast_kind kind);
ast_node const* ast_cast_const (ast_node const* object, enum ast_kind kind);

#define SELF(kind)              self_type      * self = (self_type      *)ast_cast_mutable (object, kind)
#define CONST_SELF(kind)        self_type const* self = (self_type const*)ast_cast_const   (object, kind)

#define NEW_SELF(kind, loc)     (ast_node_construct ((ast_node*)(self = malloc (sizeof *self)), &vtbl, kind, loc), self)


void ast_node_construct (ast_node* self, struct ast_vtbl const* vtbl, enum ast_kind kind, struct location const* loc);

fn_destruct ast_node_destruct;
