#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <unistd.h> // sleep

int main(void)
{

  struct timeval start, stop;
  double secs = 0;

  gettimeofday(&start, NULL);

  //printf("Do stuff  here\n");
  usleep(300);
  usleep(300);

  gettimeofday(&stop, NULL);
  secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
  printf("time taken %f\n", secs);
  return 0;
}