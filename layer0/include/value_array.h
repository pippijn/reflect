#pragma once

__BEGIN_DECLS

/**
 * This data structure can contain values of any non-pointer type. It is
 * C implementation defined to store pointers here.
 * It does take ownership of the elements added to it by copying them.
 * All index accesses are zero-based.
 */
typedef struct value_array value_array;

/**
 * Create a new empty value_array. @c size is initially 0. The @c element_size
 * parameter tells the array how large the elements are that will be stored.
 *
 * Time: O(1)
 * Space: O(1)
 */
value_array *value_array_new (size_t element_size);

/**
 * Free value_array. All values contained will be freed, as well.
 *
 * Time: O(1)
 * Space: O(1)
 */
void value_array_delete (value_array *self);


/**
 * Append @c data to the value_array.
 *
 * Time: O(n) Ω(1) over @c size
 * Space: O(1)
 */
void value_array_push (value_array *self, void *data);

/**
 * Sets the @c index'th element of the value_array to the data pointed to by
 * @c src. If @c index is greater than or equal to @c size, the array will be
 * grown and elements between the old @c last and the newly added element will
 * be zero-initialised.
 *
 * Time: O(n) over @c size if @c size <= @c index
 *       O(1) otherwise
 * Space: O(n) over @c size - @c index
 */
void value_array_set (value_array *self, size_t index, void const *src);

/**
 * Removes the last element from the value_array. The operation is undefined
 * if @c size is 0.
 *
 * Time: O(1)
 * Space: O(1)
 */
void value_array_pop (value_array *self);

/**
 * Writes the first element of the value_array to @c dest. The operation is
 * undefined if @c size is 0.
 *
 * Time: O(1)
 * Space: O(1)
 */
void value_array_first (value_array const *self, void *dest);

/**
 * Writes the last element of the value_array to @c dest. The operation is
 * undefined if @c size is 0.
 *
 * Time: O(1)
 * Space: O(1)
 */
void value_array_last (value_array const *self, void *dest);

/**
 * Writes the last element of the value_array to @c dest. The operation is
 * undefined if @c index is greater than or equal to @c size.
 *
 * Time: O(1)
 * Space: O(1)
 */
void value_array_get (value_array const *self, size_t index, void *dest);

/**
 * Removes the element at @c index from the array, preserving the order.
 * The operation is undefined if @c index is greater than or equal to @c size.
 *
 * Time: O(n) over @c size
 * Space: O(1)
 */
void value_array_erase (value_array *self, size_t index);

/**
 * Removes the element at @c index from the array, not necessarily preserving
 * the ordering of the array.
 * The operation is undefined if @c index is greater than or equal to @c size.
 *
 * Time: O(n) over @c size
 * Space: O(1)
 */
void value_array_erase_unordered (value_array *self, size_t index);

/**
 * Return the number of elements in the value_array.
 *
 * Time: O(1)
 * Space: O(1)
 */
size_t value_array_size (value_array const *self);

__END_DECLS
