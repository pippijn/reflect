#include <suites.h>

int
main (int argc, char *argv[])
{
  int failed;
  SRunner *sr;

  init_reflect (argv[0]);

  sr = srunner_create (NULL);

#define SUITE(suite) srunner_add_suite (sr, suite_##suite ());
# include <gen/suites.h>
#undef SUITE

  srunner_run_all (sr, CK_NORMAL);
  failed = srunner_ntests_failed (sr);
  srunner_free (sr);

  exit_reflect ();

  return failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
