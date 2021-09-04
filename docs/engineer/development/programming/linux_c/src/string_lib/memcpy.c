/*
extern void *memcpy(void *dest, void *src, unsigned int count);
*/

// memcpy.c

#include <stdio.h>
#include <string.h>

int main(void)
{
  char *s = "Golden Global View";
  char d[20];

  memcpy(d, s, strlen(s));
  d[strlen(s)] = 0;
  printf("%s", d);


  return 0;
}