#pragma once

/**
 * This data structure is a stack of arrays.
 * All index accesses are zero-based.
 */
typedef struct array_stack array_stack;

/**
 * Create a new empty array stack. @c size and @c levels are initially both 0.
 */
array_stack *array_stack_new (void);

/**
 * Free array stack. Pointers to arrays returned by @c pop_level and
 *   @c last_level will hereafter become invalid.
 */
void array_stack_delete (array_stack *self);


/**
 * Push @c data onto the array of the current level.
 */
void array_stack_push (array_stack *self, void *data);

/**
 * Pop the last array element off the current level array and return it.
 */
void *array_stack_pop (array_stack *self);

/**
 * Return the first array element in the current level array.
 */
void *array_stack_first (array_stack const *self);

/**
 * Return the last array element in the current level array without popping
 *   it off the array.
 */
void *array_stack_last (array_stack const *self);

/**
 * Set @c data as the @c index'th array element of the current level.
 * Grows the array if required.
 * Returns the previous array element or NULL if the index was greater than
 *   @c size - 1.
 */
void *array_stack_set (array_stack *self, size_t index, void *data);

/**
 * Get the @c index'th array element of the current level. If @c index is
 *   greater than @c size, the program is aborted.
 */
void *array_stack_get (array_stack *self, size_t index);

/**
 * Return the number of elements in the current level array.
 */
size_t array_stack_size (array_stack const *self);


/**
 * Creates a new, empty array. Any previous arrays on the next level will
 *   be invalidated.
 */
void array_stack_push_level (array_stack *self);

/**
 * Return pointer to the first element of the array in the current level
 *   and decrease the level count.
 * This pointer is valid until push_level reached this level again.
 */
void **array_stack_pop_level (array_stack *self);

/**
 * Return pointer to the first element of the array in the current level.
 * This pointer is valid until a pop_level/push_level sequence reached this
 *   level again.
 */
void **array_stack_last_level (array_stack const *self);

/**
 * Return the number of levels.
 */
size_t array_stack_levels (array_stack const *self);
