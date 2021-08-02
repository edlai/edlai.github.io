/*

https://www.itread01.com/content/1547016130.html

gcc main.c -lpthread
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

static int count = 0;

#define SEC 1
#define USEC 0

void timeout(int signal)
{
  printf("Get a SIGALRM, counts = %d!\n", count);
}

int on_timer()
{
  struct itimerval tick;
  memset(&tick, 0, sizeof(tick));
  tick.it_value.tv_sec = SEC;
  tick.it_value.tv_usec = USEC;
  tick.it_interval.tv_sec = 0;
  tick.it_interval.tv_usec = 0;
  if (setitimer(ITIMER_REAL, &tick, NULL) < 0)
    printf("Set timer failed!\n");
  return 0;
}

int off_timer()
{
  struct itimerval tick;
  memset(&tick, 0, sizeof(tick));
  tick.it_value.tv_sec = 0;
  tick.it_value.tv_usec = 0;
  tick.it_interval.tv_sec = 0;
  tick.it_interval.tv_usec = 0;
  if (setitimer(ITIMER_REAL, &tick, NULL) < 0)
    printf("Set timer failed!\n");
  return 0;
}

void *func(void *arg)
{
  while (1)
  {
    printf("hello...\n");
    count++;
    if (count % 2 == 0)
    {
      on_timer();
      sleep(2);
    }
    else
      off_timer();
  }
}

int main()
{
  int res = 0;

  signal(SIGALRM, timeout);

  on_timer();
  pthread_t fd;
  pthread_create(&fd, NULL, func, NULL);

  while (1)
  {
    sleep(20);
  }
  return 0;
}