/*

gcc main.c -lrt

*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

#define errExit(msg)    \
  do                    \
  {                     \
    perror(msg);        \
    exit(EXIT_FAILURE); \
  } while (0)

void timer_handler()
{

  time_t t;
  time(&t);
  printf("\n current time is : %s",ctime(&t));

  return;
}

int main(int argc, char *argv[])
{
  timer_t timerid;
  struct sigevent sev;
  struct itimerspec its;

  sev.sigev_notify = SIGEV_SIGNAL;
  sev.sigev_signo = SIGUSR1;
  sev.sigev_value.sival_ptr = &timerid;
  signal(SIGUSR1, timer_handler);

  if (timer_create(CLOCK_MONOTONIC, &sev, &timerid) == -1)
  {
    errExit("timer_create");
  }

  its.it_value.tv_sec = 1;
  its.it_value.tv_nsec = 0;
  its.it_interval.tv_sec = 0;
  its.it_interval.tv_nsec = 500000000;

  /* 啓動定時器 */
  if (timer_settime(timerid, 0, &its, NULL) == -1)
  {
    errExit("timer_settime");
  }

  while (1)
  {
    ; //sleep(1);
  }

  timer_delete(timerid);

  exit(EXIT_SUCCESS);
}