#include <unistd.h>
#include <sys/resource.h>

#if WANT_MCHECK
# include <mcheck.h>
#else
# define mcheck(fun) 0
#endif

#if WANT_VALGRIND
# include <valgrind/valgrind.h>
#else
# define RUNNING_ON_VALGRIND 0
#endif

#define NEW_FILL 0x33
#define OLD_FILL 0xDD

#if WANT_MCHECK
static void
mem_check_abort (enum mcheck_status status)
{
  switch (status)
    {
    case MCHECK_DISABLED:
      fprintf (stderr,
               "mcheck was not called before the first allocation. "
               "No consistency checking can be done.");
      break;
    case MCHECK_HEAD:
      fprintf (stderr,
               "The data immediately before the block was modified. "
               "This commonly happens when an array index or pointer is decremented too far.");
      break;
    case MCHECK_TAIL:
      fprintf (stderr,
               "The data immediately after the block was modified. "
               "This commonly happens when an array index or pointer is incremented too far.");
      break;
    case MCHECK_FREE:
      fprintf (stderr,
               "The block was already freed.");
      break;
    case MCHECK_OK:
      fprintf (stderr,
               "No inconsistency detected, but %s was called. Aborting anyway.", __func__);
      break;
    default:
      fprintf (stderr,
               "Unhandled mcheck status: %d.", status);
    }
  abort ();
}
#endif

static bool mem_inited = false;

static void
mem_init (void)
{
  if (mem_inited)
    return;

  if (!RUNNING_ON_VALGRIND)
    {
      /* 10 minutes */
      alarm (600);
      {
        /* 2 minutes CPU time */
        struct rlimit const rlim = {
          120,
          120,
        };
        setrlimit (RLIMIT_CPU, &rlim);
      }
      {
        /* 512 MiB address space (memory) limit */
        struct rlimit const rlim = {
          512 * 1024 * 1024,
          512 * 1024 * 1024,
        };
        setrlimit (RLIMIT_AS, &rlim);
      }

    if (mcheck (mem_check_abort) == -1)
      {
        fprintf (stderr, "mcheck called too late");
        abort ();
      }
    }

  mem_inited = true;
}

void *
mem_alloc (size_t bytes)
{
  void *ptr;

  mem_init ();

  ptr = malloc (bytes);
  assert (ptr != NULL);
  if (!RUNNING_ON_VALGRIND)
    memset (ptr, NEW_FILL, bytes);
  return ptr;
}

void *
mem_realloc (void *ptr, size_t bytes)
{
  void *newptr;

  mem_init ();

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
  if (!RUNNING_ON_VALGRIND)
    if (memory != NULL)
      memset (memory, OLD_FILL, bytes);
  free (memory);
}

char *
mem_strdup (char const *string)
{
  char *newstring;

  assert (string != NULL);

  newstring = (char*)mem_alloc (strlen (string) + 1);
  strcpy (newstring, string);

  return newstring;
}

char *
mem_strndup (char const *string, size_t length)
{
  char *newstring;

  assert (string != NULL);

  newstring = (char*)mem_alloc (length + 1);
  strncpy (newstring, string, length);
  newstring[length] = '\0';

  return newstring;
}
