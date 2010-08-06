#include <check.h>
#include <suites.h>
#include "array_stack_suite.h"

Suite *
suite_array_stack (void)
{
  Suite *s = suite_create ("array_stack");

  TCase *tc_master = tcase_create ("master");
  tcase_add_checked_fixture (tc_master, setup, teardown);
  tcase_add_test (tc_master, new);
  tcase_add_test (tc_master, push_level);
  tcase_add_test (tc_master, pop_level);
  tcase_add_test (tc_master, last_pop);
  tcase_add_test (tc_master, push_pop);
  tcase_add_test (tc_master, data_storage);
  tcase_add_test (tc_master, get_set);
  tcase_add_test (tc_master, last_level);
  tcase_add_test (tc_master, pop_level2);
  tcase_add_test (tc_master, empty_stack_after_push);
  tcase_add_test (tc_master, last_level_twice);
  tcase_add_test (tc_master, last_level_twice_with_data);
  tcase_add_test (tc_master, last_level_twice_often);
  tcase_add_test (tc_master, last_level_twice_with_data_often);
  suite_add_tcase (s, tc_master);

  return s;
}
