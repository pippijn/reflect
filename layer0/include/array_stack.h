__BEGIN_DECLS

/**
 * This data structure behaves like a stack of arrays. It may be implemented
 * using a stack of arrays but this is not required.
 * All index accesses are zero-based.
 * It does not take ownership of the elements added to it.
 * All operations require a valid pointer to an array_stack to be passed to
 * them. That is to say, they do not check for NULL.
 */
typedef struct array_stack array_stack;

/**
 * Create a new empty array_stack. @c size and @c levels are initially both 0.
 *
 * Time: O(1)
 * Space: O(1)
 */
array_stack *array_stack_new (void);

/**
 * Free array_stack. Arrays returned by @c pop_level and @c last_level will
 * hereafter become invalid.
 *
 * Time: O(log n) Ω(1) over @c size
 * Space: O(1)
 */
void array_stack_delete (array_stack *self);


/**
 * Append @c data to the current level. This operation is undefined if there
 * is no current level to append the element to.
 *
 * Time: O(n) Ω(1) over @c size
 * Space: O(1)
 */
void array_stack_push (array_stack *self, void *data);


/**
 * Remove the last element from the current level and return it. If @c levels
 * is 0, meaning there is no level or @c size is 0, meaning there are no
 * elements in the current level, this operation is undefined.
 *
 * Time: O(1)
 * Space: O(1)
 */
void *array_stack_pop (array_stack *self);

/**
 * Return the first element of the current level. The same requirements
 * regarding @c levels and @c size as in @c pop apply here.
 *
 * Time: O(1)
 * Space: O(1)
 */
void *array_stack_first (array_stack const *self);

/**
 * Return the last element of the current level. The same requirements
 * regarding @c levels and @c size as in @c pop apply here.
 *
 * Time: O(1)
 * Space: O(1)
 */
void *array_stack_last (array_stack const *self);

/**
 * Set @c data as the @c index'th element of the current level.
 * If the @c index is greater than or equal to @c size, the elements between
 * the previously last element and the newly added element will be NULL.
 * Returns the previous element or NULL if the index was greater than or equal
 * to @c size.
 *
 * Time: O(n) Ω(1) over @c size
 * Space: O(n) Ω(1) over @c size
 */
void *array_stack_set (array_stack *self, size_t index, void *data);

/**
 * Get the @c index'th element of the current level. If @c index is greater
 * than or equal to @c size, this operation is undefined.
 *
 * Time: O(1)
 * Space: O(1)
 */
void *array_stack_get (array_stack *self, size_t index);

/**
 * Return the number of elements in the current level. This operations is
 * undefined if @c levels is 0.
 *
 * Time: O(1)
 * Space: O(1)
 */
size_t array_stack_size (array_stack const *self);


/**
 * Creates a new, empty array. Any previous arrays on the next level will
 * be invalidated.
 *
 * Time: O(n) Ω(1) over @c levels
 * Space: O(1)
 */
void array_stack_push_level (array_stack *self);

/**
 * Return array containing the elements of the current level and decrease the
 * level count. This may be the internal array if the array_stack was
 * implemented using a stack of arrays or a newly allocated one. The result of
 * modifying its elements is undefined.
 * This array is valid until push_level reached this level again.
 *
 * Time: O(1)
 * Space: O(1)
 */
void *const *array_stack_pop_level (array_stack *self);

/**
 * Return array containing the elements of the current level and decrease the
 * level count.
 * This array is valid until a @c pop_level / @c push_level sequence reached
 * this level again or until the next call to @c last_level.
 * The array_stack will keep ownership of this array, which means that client
 * code does not need to free it. In fact, freeing it is undefined.
 *
 * Time: O(1)
 * Space: O(1)
 */
void *const *array_stack_last_level (array_stack const *self);

/**
 * Return the number of levels. This operation never fails.
 *
 * Time: O(1)
 * Space: O(1)
 */
size_t array_stack_levels (array_stack const *self);

__END_DECLS
