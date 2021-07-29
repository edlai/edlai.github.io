// an example for add 2 values with call by value

#include <stdio.h>
#include <limits.h>
#include <stdint.h>

// Call by value
int64_t sum(int64_t a, int64_t b)
{
  // TIP: enlarge to int64_t before add two value
  return ((int64_t)a + (int64_t)b);
}

int main(void)
{
  int32_t x;
  int y = x = INT_MAX;

  int64_t s = sum(x, y);

  printf("0x%X + 0x%X = 0x%lX(%ld)\n", INT32_MAX, INT32_MAX, s, s);

  return 0;
}