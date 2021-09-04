// https://xiwan.io/archive/string-split-strtok-strtok-r-strsep.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  const char *const str = "MAC-:00-1C-42-A7-F1-D9";
  const char *const delim = "-:";
  char *const dupstr = strdup(str);
  char *sepstr = dupstr;
  char *substr = NULL;
  int count = 0;

  printf("original string: %s (@%p)\n", sepstr, sepstr);
  substr = strsep(&sepstr, delim);

  do
  {
    printf("#%d sub string: %s (@%p)\n", count++, substr, substr);
    substr = strsep(&sepstr, delim);
  } while (substr);

  printf("original string after 'strsep': ");
  for (count = 0; count < strlen(str); count++)
  {
    printf("%c", dupstr[count] ?: '*');
  }
  printf(" (@%p)\n", sepstr);

  free(dupstr);

  return 0;
}