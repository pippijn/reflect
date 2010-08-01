typedef struct pt_node pt_node;

/*
 * node base
 */

/* refcounting */
pt_node*                pt_node_ref            (pt_node *self);
pt_node*                pt_node_ref_ornull     (pt_node *self);
void                    pt_node_unref          (pt_node *self);
void                    pt_node_unref_ornull   (pt_node *self);

/* accessors */
struct location const  *pt_node_location       (pt_node const *self);

/* methods */
void                    pt_node_print          (pt_node const *self, FILE *fh);
