#include <stack.h>

static stack *stk;

static void
setup (void)
{
  stk = stack_new ();
}

static void
teardown (void)
{
  stack_delete (stk);
}

START_TEST (construction)
{
  fail_unless (stk != NULL);
  fail_unless (stack_size (stk) == 0);
}
END_TEST

START_TEST (push_pop)
{
  size_t up, down;

  fail_unless (stack_size (stk) == 0);
  iterate (up)
    {
      fail_unless (stack_size (stk) == up);
      stack_push (stk, NULL);
      fail_unless (stack_size (stk) == up + 1);
    }
  iterate (down)
    {
      fail_unless (stack_size (stk) == up - down);
      stack_pop (stk);
      fail_unless (stack_size (stk) == up - down - 1);
    }
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
      for (; it != et; it++)
        {
          stack_push (stk, *it);
          fail_unless (stack_top (stk) == *it,
                       "top should be \"%p\", but was \"%p\"", *it, stack_top (stk));
        }
    }
  fail_unless (stack_size (stk) == i * table_size);
  iterate (i)
    {
      char *const *it = table + table_size - 1;
      char *const *et = table - 1;
      for (; it != et; it--)
        {
          fail_unless (stack_top (stk) == *it,
                       "top should be \"%p\", but was \"%p\" (size=%d)",
                       *it, stack_top (stk), stack_size (stk));
          fail_unless (strcmp (stack_pop (stk), *it) == 0);
        }
    }
  fail_unless (stack_size (stk) == 0);
}
END_TEST
