/*

extern int memcmp(void *buf1, void *buf2, unsigned int count);
*/

// memcmp.c

#include <stdio.h>
#include <string.h>

int main(void)
{
  char *s1 = "Hello, world!!!";
  char *s2 = "Hello, World!!!";
  int r;

  r = memcmp(s1, s2, strlen(s1));

  if (!r)
    printf("s1 and s2 are identical\n");
  else if (r < 0)
    printf("s1 less than s2\n");
  else
    printf("s1 greater than s2\n");

  return 0;
}
