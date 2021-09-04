// https://www.youtube.com/watch?v=83z6dQ_OKSQ&t=8s&ab_channel=FeisStudio

#include <stdio.h>

int main(void)
{

  int intVar = 0x31;
  void *voidptr = &intVar;

  int *intptr = voidptr;
  printf("%d\n", *intptr);

  char *charptr = voidptr;
  printf("0x%02X: %c\n", *charptr, *charptr);

  return 0;
}