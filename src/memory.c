#include <memman.h>

#define NEW_FILL 0xdd
#define OLD_FILL 0xaa

/*
 * We may not always want to do this. Specifically, if running under valgrind,
 * this will hide bugs valgrind would otherwise find.
 */
#define FILL_MEMORY 1

void *
alloc (size_t bytes)
{
  void *ptr;

  ptr = malloc (bytes);
  assert (ptr != NULL);
#if FILL_MEMORY
  memset (ptr, NEW_FILL, bytes);
#endif
  return ptr;
}

void
sever (void *memory, size_t bytes)
{
#if FILL_MEMORY
  memset (memory, OLD_FILL, bytes);
#endif
  free (memory);
}
