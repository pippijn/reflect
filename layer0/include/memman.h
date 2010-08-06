#pragma once

/**
 * Initialise the memory subsystem. This registers the malloc check functions
 * and sets resource limits.
 */
void mem_init (void);

/**
 * Allocate an object of @c bytes chars. If it fails, it aborts the program.
 * This function initialises the memory with a char that is not 0x00. Clients
 * should therefore initialise the memory again, themselves.
 */
void* mem_alloc (size_t bytes);

/**
 * This function is to @c realloc what @c mem_alloc is to @c malloc, however, it
 * does not initialise the additionally allocated memory, unless @c ptr is NULL.
 */
void* mem_realloc (void *ptr, size_t bytes);

/**
 * Free a chunk of memory of @c bytes chars. This function never fails. It
 * overwrites the memory so that using it after calling @c mem_free is more
 * likely to fail. If @c memory is NULL, this function does nothing.
 */
void mem_free (void *memory, size_t bytes);
