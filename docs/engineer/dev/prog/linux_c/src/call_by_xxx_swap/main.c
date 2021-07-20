#include <stdio.h>

void swap_call_by_value(int a, int b) // call by value
{
  int tmp = a;
  a = b;
  b = tmp;
}

void swap_call_by_address(int *p, int *q)
{
  int tmp = *p;
  *p = *q;
  *q = tmp;
}

void swap_call_by_address_xor(int *p, int *q)
{
  *p ^= *q;
  *q ^= *p;
  *p ^= *q;
}

#if (0)
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
  printf("x: %d, y: %d\n", x, y);

  // correct method to swap two values by using temporary variable
  swap_call_by_address(&x, &y);
  printf("x: %d, y: %d\n", x, y);

  // correct method to swap two value by using xor
  swap_call_by_address_xor(&x, &y);
  printf("x: %d, y: %d\n", x, y);

#if (0)
  swap_call_by_reference(x, y);
#endif

  return 0;
}