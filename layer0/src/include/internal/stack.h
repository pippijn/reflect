/* internal stack interface
 * include this after include/stack.h */

__BEGIN_DECLS

/* typedef struct stack stack; */

void *stack_set (stack *self, size_t index, void *data);

void *stack_get (stack const *self, size_t index);

void *const *stack_raw (stack *const self);

__END_DECLS
