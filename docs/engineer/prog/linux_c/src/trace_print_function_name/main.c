#include <stdio.h>
#include <time.h>

#define DEBUG (1)

#ifdef DEBUG
#define BLURT(x) do { printf("%ld [%s:%s():%d] %s", time(0), __FILE__, __func__, __LINE__, x); } while(0)
#else
#define BLURT(x)
#endif

void silly_function(void)
{
  BLURT("I am here\n");
}

int main(void)
{
  BLURT("I am here\n");
  silly_function();

  return 0;
}