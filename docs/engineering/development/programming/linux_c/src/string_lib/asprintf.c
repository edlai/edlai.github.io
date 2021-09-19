#define _GNU_SOURCE


// int asprintf(char **strp, const char *fmt, ...);


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void asprintf_demo(char **dest, char const *src)
{
  char *buf;

  printf("[%s:%d:%s()] [%p] src:  %s\n", __FILE__, __LINE__, __func__, src, src);
  printf("[%s:%d:%s()] [%p] dest: %s\n", __FILE__, __LINE__, __func__, *dest, *dest);

  asprintf(&buf, "%s", src);

  printf("[%s:%d:%s()] [%p] buf:  %s\n", __FILE__, __LINE__, __func__, buf, buf);
  *dest = buf;
}

int main(void)
{

  char *dest = NULL;

  const char *src = "Hello World!!";

  asprintf_demo(&dest, src);

  printf("[%s:%d:%s()] [%p] dest:  %s\n", __FILE__, __LINE__, __func__, dest, dest);

  if (dest)
  {
    free(dest);
    dest = NULL;
  }

  return 0;
}