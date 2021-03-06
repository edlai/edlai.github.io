// https://blog.richliu.com/2016/09/01/2002/sigalarm-timer_create-%E9%80%A0%E6%88%90-cpu-sys-100-%E7%9A%84%E5%95%8F%E9%A1%8C/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <time.h>

sem_t g_timer_sem_hdlr;
int timerfd;
pthread_t sig_thread;

#define MAX_EVENT 4

static int epfd = -1;
static struct epoll_event events;
static int sig_timer;
static struct itimerspec its;
static struct epoll_event ev;

void *sig_epoll_wait(void *ptr)
{
  int numEvent = 0;
  unsigned long value;
  struct event_record *pevent = NULL;
  int i;

  while (1)
  {
    numEvent = epoll_wait(epfd, &events, 1, -1);

    for (i = 0; i < numEvent; i++)
    {

      if (epoll_ctl(epfd, EPOLL_CTL_DEL, timerfd, &ev) == -1)
        perror("[1] epoll_ctl del");

      if (timerfd_settime(timerfd, 0, &its, NULL) == -1)
        perror("[1] timerfd_settime");

      if (epoll_ctl(epfd, EPOLL_CTL_ADD, timerfd, &ev) == -1)
        perror("[1] epoll_ctl add");
      sem_post(&g_timer_sem_hdlr);
    }
  }

  return NULL;
}

void create_timer(int sig, int msec)
{

  timerfd = timerfd_create(CLOCK_MONOTONIC, 0);
  if (timerfd == -1)
    perror("timerfd_create");

  its.it_value.tv_sec = 0;
  its.it_value.tv_nsec = msec * 10000;
  its.it_interval.tv_sec = its.it_value.tv_sec;
  its.it_interval.tv_nsec = its.it_value.tv_nsec;

  if (timerfd_settime(timerfd, 0, &its, NULL) == -1)
    perror("timerfd_settime");

  // Create epoll
  epfd = epoll_create(1);
  if (epfd == -1)
    perror(" epoll_create ");

  ev.data.ptr = &sig_timer;
  sig_timer;
  ev.events = EPOLLIN | EPOLLET;

  // enable epoll

  if (epoll_ctl(epfd, EPOLL_CTL_ADD, timerfd, &ev) == -1)
    perror("[0] epoll_ctl");

  // Create Thread
  pthread_create(&sig_thread, NULL, sig_epoll_wait, NULL);
}

void main()
{
  int i = 0;
  sem_init(&g_timer_sem_hdlr, 1, 0);

  printf("Create Timer \n");
  create_timer(5566, 5); // ms
  while (1)
  {
    sem_wait(&g_timer_sem_hdlr);
    if ((i % 10000) == 0)
    {
      time_t t;
      time(&t);
      printf("\n current time is : %s", ctime(&t));
      printf("%s: hello, i=%d\n", __func__, i);
    }
    i++;
  }
  printf("exited.\n");
  return;
}