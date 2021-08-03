// bcmp.c

#include <stdio.h>
#include <string.h>

main()
{
  char *s1 = "Golden Global View";
  char *s2 = "Golden global view";
  ;

  clrscr(); // clear screen
  if (!bcmp(s1, s2, 7))
    printf("s1 equal to s2 in first 7 bytes");
  else
    printf("s1 not equal to s2 in first 7 bytes");

  getchar();
  clrscr();
  if (!bcmp(s1, s2, 12))
    printf("s1 equal to s2 in first 12 bytes");
  else
    printf("s1 not equal to s2 in first 12 bytes");

  getchar();
  return 0;
}