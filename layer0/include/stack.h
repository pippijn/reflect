#pragma once

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
 */
stack *stack_new (void);

/**
 * Free stack. Does not free its elements.
 */
void stack_delete (stack *self);


/**
 * Append @c data to the stack.
 */
void stack_push (stack *self, void *data);


/**
 * Returns the last element of the stack and removes it.
 */
void *stack_pop (stack *self);

/**
 * Returns the last element of the stack.
 */
void *stack_top (stack const *self);

/**
 * Return the number of elements in the stack.
 */
size_t stack_size (stack const *self);

__END_DECLS
