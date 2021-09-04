/*
Ref: https://zh.wikipedia.org/wiki/Volatile%E5%8F%98%E9%87%8F
gcc -S with.c -o with.s
*/

/*
SAMPLE: ACCESS COMM PORT
#define PORT 0xB00000000
unsigned int volatile * const port = (unsigned int *) PORT;
*/

#include <stdio.h>

int main()
{
  volatile int a = 10, b = 100, c = 0, d = 0;

  printf("%d", a + b);

  a = b;
  c = b;
  d = b;

  printf("%d", c + d);

  return 0;
}