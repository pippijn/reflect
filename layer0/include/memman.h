#pragma once

/**
 * Allocate an object of @c bytes chars. If it fails, it aborts the program.
 * This function initialises the memory with a char that is not 0x00. Clients
 * should therefore initialise the memory again, themselves.
 */
void* xalloc (size_t bytes);

/**
 * This function is to @c realloc what @c xalloc is to @c malloc, however, it
 * does not initialise the additionally allocated memory.
 */
void* xrealloc (void *ptr, size_t bytes);

/**
 * Free a chunk of memory of @c bytes chars. This function never fails. It
 * overwrites the memory so that using it after calling @c xfree is more
 * likely to fail.
 */
void xfree (void *memory, size_t bytes);
