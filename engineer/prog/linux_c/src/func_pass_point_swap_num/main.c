// an example for swap 2 values with call by address

#include <stdio.h>

// BAD example: call by value
void swap_call_by_value(int p, int q)
{
  int tmp = p;
  p = q;
  q = tmp;
}

// GOOD example: call by address
void swap_call_by_address(int *p, int *q)
{
  int tmp = *p;
  *p = *q;
  *q = tmp;
}

// GOOD example with XOR: call by address
void swap_call_by_address_xor_1(int *p, int *q)
{
  *p ^= *q;
  *q ^= *p;
  *p ^= *q;
}

// GOOD example with XOR: call by address
void swap_call_by_address_xor_2(int *p, int *q)
{
  *p ^= *q ^= *p ^= *q;
}

#if (0)  // There is no call by reference in C
void swap_call_by_reference(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}
#endif

int main(void)
{
  int x = 2, y = 3;
  printf("x: %d, y: %d\n", x, y);

  // incorrect method to swap two values
  swap_call_by_value(x, y);
  printf("BAD example:  x: %d, y: %d\n", x, y);

  // correct method to swap two values by using temporary variable
  swap_call_by_address(&x, &y);
  printf("GOOD example: x: %d, y: %d\n", x, y);

  // correct method to swap two value by using xor
  swap_call_by_address_xor_1(&x, &y);
  printf("GOOD example: x: %d, y: %d\n", x, y);

  swap_call_by_address_xor_2(&x, &y);
  printf("GOOD example: x: %d, y: %d\n", x, y);

#if (0)
  swap_call_by_reference(x, y);
#endif

  return 0;
}