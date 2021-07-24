#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>
#include <time.h>

void PrintMsg(int Num)
{
  time_t t;
  time(&t);
  printf("\n current time is : %s", ctime(&t));
  //printf("%s \n", "Hello World");
  return;
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, PrintMsg);
  struct itimerval tick;
  tick.it_value.tv_sec = 1; //一秒鐘後將啟動定時器
  tick.it_value.tv_usec = 0;
  tick.it_interval.tv_sec = 0; //定時器啟動後，每隔1秒將執行相應的函數
  tick.it_interval.tv_usec = 500000;

  //setitimer將觸發SIGALRM信號
  int ret = setitimer(ITIMER_REAL, &tick, NULL);

  if (ret != 0)
  {
    printf("Set timer error.%s \n", strerror(errno));
    return -1;
  }

  printf("Wait！ \n");
  getchar();
  return 0;
}