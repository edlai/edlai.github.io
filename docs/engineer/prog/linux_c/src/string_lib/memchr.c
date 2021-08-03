/*

extern void *memchr(void *buf, char ch, unsigned count);

*/

// memchr.c

#include <stdio.h>
#include <string.h>

int main(void)
{
  char *s = "Hello, World!!!";
  char *p;

  p = memchr(s, 'W', strlen(s));
  if (p)
    printf("%s\n", p);
  else
    printf("Not Found!");

  return 0;
}