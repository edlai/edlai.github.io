#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <unistd.h> // sleep

void timediff()
{
  static struct timeval record_stamp;
  struct timeval curr_stamp;

  gettimeofday(&curr_stamp, NULL);

  if (0 == record_stamp.tv_sec && 0 == record_stamp.tv_usec)
  {
    printf(">>> record time stamp\n");
  }
  else
  {
    printf(">>> diff   time stamp\n");
    double secs = 0;
    secs = (double)(curr_stamp.tv_usec - record_stamp.tv_usec) / 1000000 + (double)(curr_stamp.tv_sec - record_stamp.tv_sec);
    printf(">>> time   taken %16f\n", secs);
  }
  record_stamp = curr_stamp;
}

int main(void)
{
  timediff();
  usleep(300);
  timediff();
  sleep(1);
  timediff();
  return 0;
}