#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bool_demo()
{
  _Bool m = 1;
  _Bool n = 0;

  printf("m = %d, n= %d\n", m, n);

  printf("sizeof(bool)=%zu\n", sizeof(_Bool));
}

int main()
{
  bool_demo();
  return 0;
}