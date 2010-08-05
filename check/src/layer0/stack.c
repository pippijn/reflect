#include <check.h>
#include <suites.h>
#include "stack_suite.h"

Suite *
suite_stack (void)
{
  Suite *s = suite_create ("stack");

  TCase *tc_master = tcase_create ("master");
  tcase_add_checked_fixture (tc_master, setup, teardown);
  tcase_add_test (tc_master, construction);
  tcase_add_test (tc_master, push_pop);
  tcase_add_test (tc_master, data_storage);
  suite_add_tcase (s, tc_master);

  return s;
}
