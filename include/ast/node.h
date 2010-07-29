typedef struct ast_node ast_node;

/*
 * node base
 */

/* destructor */
void                    ast_node_delete         (ast_node* self);

/* accessors */
struct location const*  ast_node_location       (ast_node const* self);

/* methods */
void                    ast_node_print          (ast_node const* self, FILE* fh);
