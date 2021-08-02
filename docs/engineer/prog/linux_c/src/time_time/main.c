// https://www.runoob.com/w3cnote/c-time-func-summary.html

#include <stdio.h>
#include <time.h>

int main ()
{
   time_t curtime;
   time(&curtime);

   printf("Current Time = %s", ctime(&curtime));

   return(0);
}