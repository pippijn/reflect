#pragma once

__BEGIN_DECLS

/**
 * This data structure is a stack of arrays.
 * All index accesses are zero-based.
 */
typedef struct stack stack;

/**
 * Create a new empty array stack. @c size and @c levels are initially both 0.
 */
stack *stack_new (void);

/**
 * Free array stack. Pointers to arrays returned by @c pop_level and
 *   @c last_level will hereafter become invalid.
 */
void stack_delete (stack *self);


/**
 * Push @c data onto the array of the current level.
 */
void stack_push (stack *self, void *data);


/**
 * Pop the last array element off the current level array and return it.
 */
void *stack_pop (stack *self);

/**
 * Return the last array element in the current level array without popping
 *   it off the array.
 */
void *stack_top (stack const *self);

/**
 * Return the number of elements in the current level array.
 */
size_t stack_size (stack const *self);

__END_DECLS
