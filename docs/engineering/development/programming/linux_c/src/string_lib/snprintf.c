#define _GNU_SOURCE

/*
int vasprintf(char **strp, const char *fmt, va_list ap);
int asprintf(char **strp, const char *fmt, ...);
int snprintf (char * s, size_t n, const char * format, ... );
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void snprintf_demo(char **dest, char const *src)
{
  char *str = NULL;
  int len = strlen("strings ") + strlen(src) + 1;
  str = (char *)malloc(len);
  snprintf(str, len, "strings %s", src);
  printf("str: %s\n", str);
  //*dest = str;
}

void asprintf_demo(char **dest, char const *src)
{
  char *str;
  printf("[%d] [%p] src:  %s\n", __LINE__, src, src);
  printf("[%d] [%p] dest: %s\n", __LINE__, *dest, *dest);

  asprintf(&str, "strings %s", src);

  printf("str  [%p] str:  %s\n", str, str);
  *dest = str;
}

int main(void)
{
  char *snprintf_demo_dest;
  char *asprintf_demo_dest;

  char test[] = "test_1";

  //snprintf_demo(asprintf_demo_dest, test);
  printf("[%d] [%p] asprintf_demo_dest: %s\n", __LINE__, asprintf_demo_dest, asprintf_demo_dest);
  printf("[%d] [%p] test: %s\n", __LINE__, test, test);

  //printf("[%d] [%p] asprintf_demo_dest: %s\n", __LINE__, asprintf_demo_dest, asprintf_demo_dest);

  asprintf_demo(&snprintf_demo_dest, test);

  printf("[%p] asprintf_demo_dest: %s\n", asprintf_demo_dest, asprintf_demo_dest);
  //printf("[%p] snprintf_demo_dest: %s\n", asprintf_demo_dest, snprintf_demo_dest);

  if (asprintf_demo_dest)
  {
    free(asprintf_demo_dest);
    asprintf_demo_dest = NULL;
  }
  if (snprintf_demo_dest)
  {
    free(snprintf_demo_dest);
    snprintf_demo_dest = NULL;
  };

  return 0;
}