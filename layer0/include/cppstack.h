#pragma once

__BEGIN_DECLS

/**
 * This data structure is a stack of arrays.
 * All index accesses are zero-based.
 */
typedef struct cppstack cppstack;

/**
 * Create a new empty array stack. @c size and @c levels are initially both 0.
 */
cppstack *cppstack_new (void);

/**
 * Free array stack. Pointers to arrays returned by @c pop_level and
 *   @c last_level will hereafter become invalid.
 */
void cppstack_delete (cppstack *self);


/**
 * Push @c data onto the array of the current level.
 */
void cppstack_push (cppstack *self, void *data);


/**
 * Pop the last array element off the current level array and return it.
 */
void *cppstack_pop (cppstack *self);

/**
 * Return the last array element in the current level array without popping
 *   it off the array.
 */
void *cppstack_top (cppstack const *self);

/**
 * Return the number of elements in the current level array.
 */
size_t cppstack_size (cppstack const *self);

__END_DECLS
