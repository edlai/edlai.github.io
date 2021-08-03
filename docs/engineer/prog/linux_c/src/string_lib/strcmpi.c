// strnicmp.c

#include <stdio.h>
#include <string.h>

int main(void)
{
  char *s1 = "Hello, Programmers!";
  char *s2 = "Hello, programmers!";
  int r;

  r = strnicmp(s1, s2, strlen(s1));
  if (!r)
    printf("s1 and s2 are identical");
  else if (r < 0)
    printf("s1 less than s2");
  else
    printf("s1 greater than s2");


  return 0;
}
