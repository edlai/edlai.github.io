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

int util_str_append(char **buf, const char *format, ...)
{
  char *str = NULL;
  char *old_buf = NULL;
  char *new_buf = NULL;

  va_list arg_ptr;
  va_start(arg_ptr, format);
  vasprintf(&str, format, arg_ptr);
  va_end(arg_ptr);

  // save old string
  asprintf(&old_buf, "%s", (*buf == NULL ? "" : *buf));

  // calloc new string memory
  new_buf = (char *)calloc(strnlen(old_buf, UINT_MAX) + strnlen(str, UINT_MAX) + 1, sizeof(char));

  snprintf(new_buf, strnlen(old_buf, UINT_MAX) + strnlen(str, UINT_MAX) + 1, "%s%s", old_buf, str);

  if (*buf) {
    free(*buf);
    *buf = NULL;
  }
  *buf = new_buf;

  if (old_buf) {
    free(old_buf);
    old_buf = NULL;
  }

  if (str) {
    free(str);
    str = NULL;
  }

  return 0;
}

#define keys (sizeof(key) / sizeof(key[0]))

int main(void)
{

  char *all_string = NULL;
  char key[][64] = {"Accept", "Accept-Charset", "Accept-Encoding"};
  char val[][64] = {"Accept: text/plain", "Accept-Charset: utf-8", "Accept-Encoding: gzip, deflate"};

  for (int i = 0; i < keys; i++)
  {
    util_str_append(&all_string, "%s: %s\r\n", key[i], val[i]);
  }
  util_str_append(&all_string, "\r\n");

  printf("%s\n", all_string);

  if (all_string)
  {
    free(all_string);
    all_string = NULL;
  }

  printf("well done\n");

  return 0;
}
