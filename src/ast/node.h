typedef void fn_destruct (ast_node* node);
typedef void fn_print (ast_node const* node, FILE* fh);

enum ast_kind
{
  AST_NODE,

  AST_FOR_STATEMENT,
  AST_TOKEN,
};


struct ast_vtbl
{
  struct ast_vtbl const* base;
  enum ast_kind kind;
  fn_destruct* destruct;
  fn_print* print;
};


struct ast_node
{
  struct ast_vtbl const* vtbl;
  struct location location;
};


void pure_virtual (void);
bool ast_kind_is (ast_node const* object, enum ast_kind kind);
bool ast_kind_derived (ast_node const* object, enum ast_kind kind);
ast_node* ast_cast_mutable (ast_node* object, enum ast_kind kind);
ast_node const* ast_cast_const (ast_node const* object, enum ast_kind kind);

#define SELF()                  self_type      * self = (self_type      *)ast_cast_mutable (object, vtbl->kind)
#define CONST_SELF()            self_type const* self = (self_type const*)ast_cast_const   (object, vtbl->kind)

#define NEW_SELF(loc)           (ast_node_construct ((ast_node*)(self = malloc (sizeof *self)), vtbl, loc), self)
#define BASE_DESTRUCT()         self->base.vtbl->base->destruct (&self->base)


void ast_node_construct (ast_node* self, struct ast_vtbl const* vtbl, struct location const* loc);

extern struct ast_vtbl const ast_node_vtbl;

fn_destruct ast_node_destruct;
fn_print ast_node_print;
