// https://fresh2refresh.com/c-programming/c-strings/c-strdup-function/

#include <stdio.h>
#include <string.h>
int main()
{
  char *p1 = "Raja";
  char *p2;
  p2 = strdup(p1);

  printf("Duplicated string is : %s", p2);
  return 0;
}