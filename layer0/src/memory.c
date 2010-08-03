#include <memman.h>

#define NEW_FILL 0xdd
#define OLD_FILL 0xaa

/*
 * We may not always want to do this. Specifically, if running under valgrind,
 * this will hide bugs valgrind would otherwise find.
 */
#define FILL_MEMORY 1

void *
mem_alloc (size_t bytes)
{
  void *ptr;

  ptr = malloc (bytes);
  assert (ptr != NULL);
#if FILL_MEMORY
  memset (ptr, NEW_FILL, bytes);
#endif
  return ptr;
}

void *
mem_realloc (void *ptr, size_t bytes)
{
  void *newptr;

  if (ptr == NULL)
    newptr = mem_alloc (bytes);
  else
    newptr = realloc (ptr, bytes);
  assert (newptr != NULL);
  return newptr;
}

void
mem_free (void *memory, size_t bytes)
{
#if FILL_MEMORY
  if (memory != NULL)
    memset (memory, OLD_FILL, bytes);
#endif
  free (memory);
}
