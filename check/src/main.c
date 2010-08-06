#include <suites.h>

int
main (void)
{
  int failed;
  SRunner *sr;

  mem_init ();
  
  sr = srunner_create (NULL);

#define SUITE(suite) srunner_add_suite (sr, suite_##suite ());
# include <gen/suites.h>
#undef SUITE

  srunner_run_all (sr, CK_NORMAL);
  failed = srunner_ntests_failed (sr);
  srunner_free (sr);

  return failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
