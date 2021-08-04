// C program to demonstrate strdup()
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

int main()
{
  char source[] = "GeeksForGeeks";

  // A copy of source is created dynamically
  // and pointer to copy is returned.
  char *target = strdupa(source);

  printf("%s", target);
  return 0;
}