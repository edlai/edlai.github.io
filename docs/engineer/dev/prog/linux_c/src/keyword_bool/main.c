/*
In C _Bool is a type and bool, true and false are macros defined in stdbool.h

ISO C11 standard states (in section 6.2.5 Types )

An object declared as type _Bool is large enough to store the values 0 and 1.

stdbool.h defines 4 macros.

bool which expands to _Bool
true which expands to 1
false which expands to 0
__bool_true_false_are_defined which expands to 1.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bool_demo()
{

  // use keyword _Bool to define the type of variable
  _Bool a = 0;
  _Bool b = 1;
  _Bool c = 2;
  _Bool d = 3;

  // use keyword _Bool to define the type of variable
  printf("sizeof(bool)=%zu\n", sizeof(_Bool));
  printf("a = %d, sizeof(a)=%zu\n", a, sizeof(a));
  printf("b = %d, sizeof(b)=%zu\n", b, sizeof(b));
  printf("c = %d, sizeof(c)=%zu\n", c, sizeof(c));
  printf("d = %d, sizeof(d)=%zu\n", d, sizeof(d));

}

int main()
{
  bool_demo();
  return 0;
}