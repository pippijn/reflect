__BEGIN_DECLS

/**
 * This data structure behaves like a stack.
 * It does not take ownership of the elements added to it.
 * All index accesses are zero-based.
 *
 * http://en.wikipedia.org/wiki/Stack_(data_structure)
 */
typedef struct stack stack;

/**
 * Create a new empty stack. @c size is initially 0.
 *
 * Time: O(1)
 * Space: O(1)
 */
stack *stack_new (void);

/**
 * Free stack. Does not free its elements.
 *
 * Time: O(log n) Ω(1) over @c size
 * Space: O(1)
 */
void stack_delete (stack *self);


/**
 * Append @c data to the stack.
 *
 * Time: O(n) Ω(1) over @c size
 * Space: O(1)
 */
void stack_push (stack *self, void *data);


/**
 * Returns the last element of the stack and removes it.
 *
 * Time: O(1)
 * Space: O(1)
 */
void *stack_pop (stack *self);

/**
 * Returns the last element of the stack.
 *
 * Time: O(1)
 * Space: O(1)
 */
void *stack_top (stack const *self);

/**
 * Return the number of elements in the stack.
 *
 * Time: O(1)
 * Space: O(1)
 */
size_t stack_size (stack const *self);

__END_DECLS
