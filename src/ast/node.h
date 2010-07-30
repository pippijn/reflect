typedef void fn_destruct (ast_node* node);
typedef void fn_print (ast_node const* node, FILE* fh);

enum ast_kind
{
  AST_NODE,

  AST_AUTO_STR_CLASS_SPEC,
  AST_BREAK_STATEMENT,
  AST_CASE_LABEL_STATEMENT,
  AST_CHAR_TYPE_SPEC,
  AST_CONST_TYPE_QUALIFIER,
  AST_CONTINUE_STATEMENT,
  AST_DO_STATEMENT,
  AST_DOUBLE_TYPE_SPEC,
  AST_DEFAULT_LABEL_STATEMENT,
  AST_ENUMERATOR,
  AST_EXPRESSION_STATEMENT,
  AST_EXTERN_STR_CLASS_SPEC,
  AST_FLOAT_TYPE_SPEC,
  AST_FOR_STATEMENT,
  AST_GOTO_STATEMENT,
  AST_IF_STATEMENT,
  AST_INT_TYPE_SPEC,
  AST_LONG_TYPE_SPEC,
  AST_LABEL_STATEMENT,
  AST_REGISTER_STR_CLASS_SPEC,
  AST_RETURN_STATEMENT,
  AST_SHORT_TYPE_SPEC,
  AST_SIGNED_TYPE_SPEC,
  AST_STATIC_STR_CLASS_SPEC,
  AST_SWITCH_STATEMENT,
  AST_TOKEN,
  AST_TYPEDEF_STR_CLASS_SPEC,
  AST_UNSIGNED_TYPE_SPEC,
  AST_VOID_TYPE_SPEC,
  AST_VOLATILE_TYPE_QUALIFIER,
  AST_WHILE_STATEMENT,
};


struct ast_vtbl
{
  struct type_info
  {
    struct ast_vtbl const* base;
    char const* name;
    enum ast_kind kind;
  } ti;
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

#define SELF()                  self_type      * self = (self_type      *)ast_cast_mutable (object, vtbl->ti.kind)
#define CONST_SELF()            self_type const* self = (self_type const*)ast_cast_const   (object, vtbl->ti.kind)

#define NEW(class, ...)         ({ self_type* self = malloc (sizeof *self); ast_##class##_construct (self, __VA_ARGS__); &self->base; })
#define BASE_CTOR(base, ...)    ast_##base##_construct ((ast_##base*)self, vtbl, __VA_ARGS__)
#define BASE_DTOR()             self->base.vtbl->ti.base->destruct (&self->base)

/* helper macros */

#define ACCESSOR(base, elem)                    \
ast_node*                                       \
ast_##base##_##elem (ast_node const *object)    \
{                                               \
  CONST_SELF ();                                \
  return self->elem;                            \
}

#define COMPUTE_LOC(start_node, end_node)       \
  do {                                          \
    struct location const *start, *end;         \
    start = ast_node_location (start_node);     \
    end   = ast_node_location (end_node);       \
                                                \
    loc.first_line = start->first_line;         \
    loc.first_column = start->first_column;     \
    loc.last_line = end->last_line;             \
    loc.last_column = end->last_column;         \
  } while (0)


extern struct ast_vtbl const ast_node_vtbl;


void ast_node_construct (ast_node* self, struct ast_vtbl const* vtbl, struct location const* loc);

fn_destruct ast_node_destruct;
#if 0
fn_print ast_node_print;
#endif
