// bzero.c

// extern void bzero(void *s, int n);

#include <syslib.h>
#include <string.h>

main()
{
  struct
  {
    int a;
    char s[5];
    float f;
  } tt;

  char s[20];

  bzero(&tt, sizeof(tt)); // struct initialization to zero
  bzero(s, 20);

  clrscr();
  printf("Initail Success");

  getchar();
  return 0;
}