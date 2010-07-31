typedef struct ast_node ast_node;

/*
 * node base
 */

/* refcounting */
ast_node*               ast_node_ref            (ast_node *self);
ast_node*               ast_node_ref_ornull     (ast_node *self);
void                    ast_node_unref          (ast_node *self);
void                    ast_node_unref_ornull   (ast_node *self);

/* accessors */
struct location const  *ast_node_location       (ast_node const *self);

/* methods */
void                    ast_node_print          (ast_node const *self, FILE *fh);
