#include <cpparray_stack.h>

static cpparray_stack *stk;

static void
setup (void)
{
  stk = cpparray_stack_new ();
}

static void
teardown (void)
{
  cpparray_stack_delete (stk);
}

START_TEST (new)
{
  fail_unless (stk != NULL);
  fail_unless (cpparray_stack_levels (stk) == 0);
}
END_TEST

START_TEST (push_level)
{
  cpparray_stack_push_level (stk);
  fail_unless (cpparray_stack_levels (stk) == 1);
  fail_unless (cpparray_stack_size (stk) == 0);
}
END_TEST

START_TEST (pop_level)
{
  cpparray_stack_push_level (stk);
  cpparray_stack_pop_level (stk);
  fail_unless (cpparray_stack_levels (stk) == 0);
}
END_TEST

START_TEST (push_pop)
{
  size_t up, down;

  fail_unless (cpparray_stack_levels (stk) == 0);
  iterate (up)
    {
      fail_unless (cpparray_stack_levels (stk) == up);
      cpparray_stack_push_level (stk);
      fail_unless (cpparray_stack_levels (stk) == up + 1);
    }
  iterate (down)
    {
      fail_unless (cpparray_stack_levels (stk) == up - down);
      cpparray_stack_pop_level (stk);
      fail_unless (cpparray_stack_levels (stk) == up - down - 1);
    }
  fail_unless (cpparray_stack_levels (stk) == 0);
}
END_TEST

START_TEST (data_storage)
{
  size_t i;
#include "data/strings.h"

  iterate (i)
    {
      char *const *it = table;
      char *const *et = table + table_size;
      cpparray_stack_push_level (stk);
      for (; it != et; it++)
        {
          cpparray_stack_push (stk, *it);
          fail_unless (cpparray_stack_last (stk) == *it,
                       "last should be \"%p\", but was \"%p\"", *it, cpparray_stack_last (stk));
          fail_unless (cpparray_stack_first (stk) == *table,
                       "first should be \"%p\", but was \"%p\"", *table, cpparray_stack_first (stk));
        }
      fail_unless (cpparray_stack_size (stk) == table_size);
    }
  fail_unless (cpparray_stack_levels (stk) == i);
  iterate (i)
    {
      char *const *it = table + table_size - 1;
      char *const *et = table - 1;
      fail_unless (cpparray_stack_size (stk) == table_size);
      for (; it != et; it--)
        {
          fail_unless (cpparray_stack_last (stk) == *it,
                       "last should be \"%p\", but was \"%p\"", *it, cpparray_stack_last (stk));
          if (it == table)
            fail_unless (cpparray_stack_last (stk) == cpparray_stack_first (stk),
                         "last should be first");
          fail_unless (cpparray_stack_pop (stk) == *it,
                       "last should be \"%p\", but was \"%p\"", *it, cpparray_stack_last (stk));
        }
      fail_unless (cpparray_stack_size (stk) == 0);
      cpparray_stack_pop_level (stk);
    }
  fail_unless (cpparray_stack_levels (stk) == 0);
}
END_TEST

START_TEST (get_set)
{
  size_t i;

  cpparray_stack_push_level (stk);
  iterate (i)
    {
      cpparray_stack_push (stk, "hello");
    }

  fail_unless (cpparray_stack_size (stk) == ITERATIONS);
  cpparray_stack_set (stk, ITERATIONS - 1, "last item");
  fail_unless (cpparray_stack_size (stk) == ITERATIONS);
  fail_unless (cpparray_stack_get (stk, ITERATIONS - 1) == cpparray_stack_last (stk));
  fail_unless (strcmp (cpparray_stack_get (stk, ITERATIONS - 1), "last item") == 0);
}
END_TEST

START_TEST (last_level)
{
  size_t i;
  void *const *array;

  iterate (i)
    {
      size_t j;
      cpparray_stack_push_level (stk);
      iterate (j)
        {
          cpparray_stack_push (stk, "hello");
        }
    }

  fail_unless (cpparray_stack_size (stk) == ITERATIONS);
  fail_unless (cpparray_stack_levels (stk) == ITERATIONS);

  array = cpparray_stack_last_level (stk);

  iterate (i)
    {
      fail_unless (strcmp (array[i], "hello") == 0,
                   "expected array[%d] to be \"%s\", but got \"%s\"", i, "hello", array[i]);
    }
}
END_TEST

START_TEST (pop_level2)
{
  size_t i;
  void *const *array;

  cpparray_stack_push_level (stk);
  iterate (i)
    {
      size_t j;
      cpparray_stack_push_level (stk);
      iterate (j)
        {
          cpparray_stack_push (stk, "hello");
        }
    }

  fail_unless (cpparray_stack_size (stk) == ITERATIONS);
  fail_unless (cpparray_stack_levels (stk) == ITERATIONS + 1);

  array = cpparray_stack_pop_level (stk);
  fail_unless (array != NULL);

  iterate (i)
    {
      cpparray_stack_pop_level (stk);
    }

  iterate (i)
    {
      fail_unless (strcmp (array[i], "hello") == 0,
                   "expected array[%d] to be \"%s\", but got \"%s\"", i, "hello", array[i]);
    }
}
END_TEST
