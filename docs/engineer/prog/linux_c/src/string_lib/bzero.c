// bzero.c

// extern void bzero(void *s, int n);

#include <stdio.h>
#include <string.h>

int main(void)
{
  struct
  {
    int id;
    char name[5];
    float fee;
  } tt;

  char src[20];

  bzero(&tt, sizeof(tt)); // struct initialization to zero
  bzero(src, 20);

  printf("id:   %d\n", tt.id);
  printf("name: \"%s\"\n", tt.name);
  printf("fee:  %f\n", tt.fee);

  printf("src:  %s\n", src);

  printf("Initail Success\n");

  return 0;
}