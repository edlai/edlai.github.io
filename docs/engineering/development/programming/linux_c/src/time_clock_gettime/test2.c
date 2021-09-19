#include <time.h>
#include <stdio.h>

int main()
{
  struct timespec tt;
  clock_getres(CLOCK_REALTIME, &tt);
  printf("resolution: %ld\n", tt.tv_nsec);
  return 0;
}