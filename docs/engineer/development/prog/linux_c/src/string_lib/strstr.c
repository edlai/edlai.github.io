// https://beginnersbook.com/2014/01/c-functions-examples/

// extern char *strstr (const char *__haystack, const char *__needle

#include <stdio.h>
#include <string.h>
int main(void)
{
  char inputstr[] = "String Function in C at BeginnersBook.COM";
  printf("Output string is: %s\n", strstr(inputstr, "Begi"));
  return 0;
}