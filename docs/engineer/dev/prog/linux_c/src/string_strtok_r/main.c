#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void test_strtok()
{
  const char *const str = "MAC-:00-1C-42-A7-F1-D9";
  const char *const delim = "-:";
  char *const dupstr = strdup(str);
  char *substr = NULL;
  int count = 0;

  printf("original string: %s (@%p)\n", dupstr, dupstr);

  substr = strtok(dupstr, delim);
  do
  {
    printf("#%d sub string: %s (@%p)\n", count++, substr, substr);
    substr = strtok(NULL, delim);
  } while (substr);

  printf("original string after 'strtok': ");
  for (count = 0; count < strlen(str); count++)
  {
    printf("%c", dupstr[count] ?: '*');
  }
  printf(" (@%p)\n", dupstr);

  free(dupstr);
}

void test_strtok_r()
{
  const char *const str = "MAC-:00-1C-42-A7-F1-D9";
  const char *const delim = "-:";
  char *const dupstr = strdup(str);
  char *saveptr = NULL;
  char *substr = NULL;
  int count = 0;

  printf("original string: %s (@%p)\n", dupstr, dupstr);
  substr = strtok_r(dupstr, delim, &saveptr);

  do
  {
    printf("#%d sub string: %s (@%p)\n", count++, substr, substr);
    substr = strtok_r(NULL, delim, &saveptr);
  } while (substr);

  printf("original string after 'strtok_r': ");
  for (count = 0; count < strlen(str); count++)
  {
    printf("%c", dupstr[count] ?: '*');
  }
  printf(" (@%p)\n", dupstr);

  free(dupstr);
}

void test_strsep()
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
}

int main(void)
{

  test_strtok();
  test_strtok_r();
  test_strsep();

  return (0);
}