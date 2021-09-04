// bcmp.c

/*
 int bcmp(const void *s1, const void * s2, int n);
int bcmp(const void *a, const void *b, size_t len)
{
  return memcmp(a, b, len);
}
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
  char *s1 = "Hello World!!";
  char *s2 = "Hello world!!";


  if (!bcmp(s1, s2, 5))
    printf("s1 equals to s2 in first 7 bytes\n");
  else
    printf("s1 does not equal to s2 in first 7 bytes\n");

  if (!bcmp(s1, s2, 7))
    printf("s1 equals to s2 in first 12 bytes\n");
  else
    printf("s1 does not equal to s2 in first 12 bytes\n");

  return 0;
}