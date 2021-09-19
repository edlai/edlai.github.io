#include <stdio.h>
#include <string.h>

int main()
{
  int len;
  const char str[] = "http://www.gitbook.net/html";
  const char ch = '.';
  char *ret;

  ret = strrchr(str, ch);

  printf("String after |%c| is - |%s|", ch, ret);

  return (0);
}