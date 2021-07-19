
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t;

int main(void)
{
  char str[] = "Hello";
  char *p = str;
  int n = 10;

  printf("%zu %zu %zu", sizeof(str), sizeof(p), sizeof(n));

  // int a[] = [ 6, 7, 8, 9, 10 ];
  //   int *p = a;
  //   *(p++) += 123;
  //   *(++p) += 123;
  // ask:
  //   the content of array a ?
}