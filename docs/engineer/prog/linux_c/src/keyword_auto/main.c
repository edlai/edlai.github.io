// https://zh.wikipedia.org/wiki/Auto_(C%2B%2B)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  auto i = 3;
  auto f = 3.14;
  auto s = '1';
  //auto s("hello");
  //auto z = new auto(9);
  //auto x1 = 5, x2 = 5.0, x3 = 'r';
  printf("i= %d\n", i);
  printf("f= %f\n", f);
  printf("s= %c\n", s);
}

/*

$ gcc main.c

main.c: In function ‘main’:
main.c:8:8: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
   auto f = 3.14;
        ^
*/