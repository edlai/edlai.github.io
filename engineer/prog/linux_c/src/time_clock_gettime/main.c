#include <time.h>
#include <stdio.h>
#include <unistd.h>

int abs(int a)
{
  return a > 0 ? a : -1 * a;
}

int main()
{
  struct timespec tt1, tt2;
  int result;
  clock_gettime(CLOCK_REALTIME, &tt1);
  result = abs(-33);
  clock_gettime(CLOCK_REALTIME, &tt2);
  printf("abs() consumes %ld nanoseconds!\n(Result of abs: %d)\n", tt2.tv_nsec - tt1.tv_nsec, result);
  return 0;
}