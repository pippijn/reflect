#include <array_stack.h>

static array_stack *stk;

static void
setup (void)
{
  stk = array_stack_new ();
}

static void
teardown (void)
{
  array_stack_delete (stk);
}

START_TEST (new)
{
  fail_unless (stk != NULL);
  fail_unless (array_stack_levels (stk) == 0);
}
END_TEST

START_TEST (push_level)
{
  array_stack_push_level (stk);
  fail_unless (array_stack_levels (stk) == 1);
  fail_unless (array_stack_size (stk) == 0);
}
END_TEST

START_TEST (pop_level)
{
  array_stack_push_level (stk);
  array_stack_pop_level (stk);
  fail_unless (array_stack_levels (stk) == 0);
}
END_TEST

START_TEST (push_pop)
{
  size_t up, down;

  fail_unless (array_stack_levels (stk) == 0);
  iterate (up)
    {
      fail_unless (array_stack_levels (stk) == up);
      array_stack_push_level (stk);
      fail_unless (array_stack_levels (stk) == up + 1);
    }
  iterate (down)
    {
      fail_unless (array_stack_levels (stk) == up - down);
      array_stack_pop_level (stk);
      fail_unless (array_stack_levels (stk) == up - down - 1);
    }
  fail_unless (array_stack_levels (stk) == 0);
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
      array_stack_push_level (stk);
      for (; it != et; it++)
        {
          array_stack_push (stk, *it);
          fail_unless (array_stack_last (stk) == *it,
                       "last should be \"%p\", but was \"%p\"", *it, array_stack_last (stk));
          fail_unless (array_stack_first (stk) == *table,
                       "first should be \"%p\", but was \"%p\"", *table, array_stack_first (stk));
        }
      fail_unless (array_stack_size (stk) == table_size);
    }
  fail_unless (array_stack_levels (stk) == i);
  iterate (i)
    {
      char *const *it = table + table_size - 1;
      char *const *et = table - 1;
      fail_unless (array_stack_size (stk) == table_size);
      for (; it != et; it--)
        {
          fail_unless (array_stack_last (stk) == *it,
                       "last should be \"%p\", but was \"%p\"", *it, array_stack_last (stk));
          if (it == table)
            fail_unless (array_stack_last (stk) == array_stack_first (stk),
                         "last should be first");
          fail_unless (array_stack_pop (stk) == *it,
                       "last should be \"%p\", but was \"%p\"", *it, array_stack_last (stk));
        }
      fail_unless (array_stack_size (stk) == 0);
      array_stack_pop_level (stk);
    }
  fail_unless (array_stack_levels (stk) == 0);
}
END_TEST

START_TEST (get_set)
{
  size_t i;
  void *r;

  array_stack_push_level (stk);
  iterate (i)
    {
      array_stack_push (stk, "hello");
    }

  fail_unless (array_stack_size (stk) == ITERATIONS);
  r = array_stack_set (stk, ITERATIONS - 1, "last item");
  fail_unless (r != NULL, "could not set last item");
  fail_unless (array_stack_size (stk) == ITERATIONS);
  fail_unless (array_stack_get (stk, ITERATIONS - 1) == array_stack_last (stk));
  fail_unless (strcmp (array_stack_get (stk, ITERATIONS - 1), "last item") == 0,
      "expected \"last item\", got \"%s\"", array_stack_get (stk, ITERATIONS - 1));
}
END_TEST

START_TEST (last_level)
{
  size_t i;
  void *const *array;

  iterate (i)
    {
      size_t j;
      array_stack_push_level (stk);
      iterate (j)
        {
          array_stack_push (stk, "hello");
        }
    }

  fail_unless (array_stack_size (stk) == ITERATIONS);
  fail_unless (array_stack_levels (stk) == ITERATIONS);

  array = array_stack_last_level (stk);

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

  array_stack_push_level (stk);
  iterate (i)
    {
      size_t j;
      array_stack_push_level (stk);
      iterate (j)
        {
          array_stack_push (stk, "hello");
        }
    }

  fail_unless (array_stack_size (stk) == ITERATIONS);
  fail_unless (array_stack_levels (stk) == ITERATIONS + 1);

  array = array_stack_pop_level (stk);
  fail_unless (array != NULL);

  iterate (i)
    {
      array_stack_pop_level (stk);
    }

  fail_unless (array_stack_levels (stk) == 0);

  iterate (i)
    {
      fail_unless (strcmp (array[i], "hello") == 0,
                   "expected array[%d] to be \"%s\", but got \"%s\"", i, "hello", array[i]);
    }
}
END_TEST

START_TEST (empty_stack_after_push)
{
  array_stack_push_level (stk);
  array_stack_push (stk, "hello");
  array_stack_pop_level (stk);
  array_stack_push_level (stk);

  fail_unless (array_stack_size (stk) == 0);
}
END_TEST
