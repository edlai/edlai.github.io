// https://stackoverflow.com/questions/10192903/time-in-milliseconds-in-c
// $ gcc main.c -lm

#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// not working => shall be CLOCK_REALTIME
uint64_t get_now_time()
{
  struct timespec spec;
  if (clock_gettime(1, &spec) == -1)
  { /* 1 is CLOCK_MONOTONIC */
    abort();
  }

  return spec.tv_sec * 1000 + lround(spec.tv_nsec / 1e6);
}

long millis1()
{
  struct timespec _t;
  clock_gettime(CLOCK_REALTIME, &_t);
  return _t.tv_sec * 1000 + lround(_t.tv_nsec / 1.0e6);
}

int64_t millis2()
{
  struct timespec now;
  timespec_get(&now, TIME_UTC);
  return ((int64_t)now.tv_sec) * 1000 + ((int64_t)now.tv_nsec) / 1000000;
}

long long current_timestamp()
{
  struct timeval te;
  gettimeofday(&te, NULL);                                         // get current time
  long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // calculate milliseconds
  // printf("milliseconds: %lld\n", milliseconds);
  return milliseconds;
}

int main(void)
{
  printf("Unix timestamp with millisecond precision: %" PRId64 "\n", time(0));
  printf("Unix timestamp with millisecond precision: %" PRId64 "\n", millis1());
  printf("Unix timestamp with millisecond precision: %" PRId64 "\n", millis2());
  // not working
  //printf("Unix timestamp with millisecond precision: %ld\n", get_now_time());
  printf("Unix timestamp with millisecond precision: %lld\n", current_timestamp());
  return 0;
}