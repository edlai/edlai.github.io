// bcopy.c

// https://doc.bccnsoft.com/docs/cfuncs/string/bcopy.html

#include <stdio.h>
#include <string.h>

#define clrscr() do { printf("\033[H\033[J"); } while(0)

int main(void)
{
  char *s = "Golden Global View";
  char d[20];

  clrscr(); // clear screen
  bcopy(s, d, 6);
  printf("s: %s\n", s);
  printf("d: %s\n", d);

  getchar();
  clrscr();
  s[13] = 0;
  bcopy(s + 7, d, 11); // bcopy ignore null in string
  printf("%s\n", s + 7);
  for (int i = 0; i < 11; i++)
    putchar(d[i]);

  getchar();
  return 0;
}