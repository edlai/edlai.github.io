// Sum 2 numbers

#include <stdio.h>
#include <limits.h>
#include <stdint.h>

// TIP: Call by value (without use start "*"")
int64_t sum(int64_t a, int64_t b)
{
  // TIP: enlarge to int64_t before add two values
  return ((int64_t)a + (int64_t)b);
}

int main(void)
{
  // TIP: better to use int32_t (not int)
  int32_t x;
  int32_t y = x = INT_MAX;

  int64_t s = sum(x, y);
  printf("0x%X + 0x%X = 0x%lX(%ld)\n", INT32_MAX, INT32_MAX, s, s);

  return 0;
}