#include <check.h>
#include <sys/time.h>

/* prime number near 2**n that is not 2**n-1 */
#define            ITERATIONS   (131)
#define      OFTEN_ITERATIONS   (1021)
#define VERY_OFTEN_ITERATIONS   (1021 * 1031)

#define very_often(i)   for (i = 0; i < VERY_OFTEN_ITERATIONS; i++)
#define often(i)        for (i = 0; i <      OFTEN_ITERATIONS; i++)
#define iterate(i)      for (i = 0; i <            ITERATIONS; i++)

#define TIMER_DECL(timer)       struct timeval timer##_start, timer##_end
#define TIMER_START(timer)      gettimeofday (&timer##_start, NULL)
#define TIMER_END(timer)                                \
do {                                                    \
  struct timeval diff;                                  \
  gettimeofday (&timer##_end, NULL);                    \
  timersub (&timer##_end, &timer##_start, &diff);       \
  printf ( "time for %s: %ld.%lds\n", #timer            \
         , diff.tv_sec, diff.tv_usec);                  \
} while (0)

#define SUITE(suite) Suite *suite_##suite (void);
# include <gen/suites.h>
#undef SUITE
