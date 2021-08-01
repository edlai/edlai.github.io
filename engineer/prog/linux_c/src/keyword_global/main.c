
// global var shall be zero even user never define it.
// local var has chance to be a unknown number. (Maybe different GCC)

#include <stdio.h>
#include <limits.h>

int global_int_1;
int global_int_2;
int global_char_1;

void func_local_value()
{
  int local_int_1;
  int local_int_2;
  int local_int_3;

  printf("[%p] local_int_1: %d   (0x%02X)\n", &local_int_1, local_int_1, local_int_1);
  printf("[%p] local_int_2: %d   (0x%02X)\n", &local_int_2, local_int_2, local_int_2);
  printf("[%p] local_int_3: %d   (0x%02X)\n", &local_int_3, local_int_3, local_int_3);
}

int main()
{
  int local_int_1;
  int local_int_2 = INT_MAX;
  unsigned int local_int_3 = UINT_MAX;

  // check the value of global_var (the default value is zero)
  printf("[%p] global_int_1: %d  (0x%02X)\n", &global_int_1, global_int_1, global_int_1);
  printf("[%p] global_int_2: %d  (0x%02X)\n", &global_int_2, global_int_2, global_int_2);
  printf("[%p] global_char_1: %c  (0x%02X)\n", &global_char_1, global_char_1, global_char_1);
  printf("==============================================================\n");
  // check the value of local_var  (the default value is not always zero)
  printf("[%p] local_int_1: %d   (0x%02X)\n", &local_int_1, local_int_1, local_int_1);
  printf("[%p] local_int_2: %u   (0x%02X)\n", &local_int_2, local_int_2, local_int_2);
  printf("[%p] local_int_3: %u   (0x%02X)\n", &local_int_3, local_int_3, local_int_3);
  printf("==============================================================\n");
  func_local_value();

  return 0;
}

/*

[0x555e691bf01c] global_int_1: 0  (0x00)
[0x555e691bf014] global_int_2: 0  (0x00)
[0x555e691bf018] global_char_1:   (0x00)
==============================================================
[0x7fffe1f2c44c] local_int_1: 21854   (0x555E)
[0x7fffe1f2c450] local_int_2: 2147483647   (0x7FFFFFFF)
[0x7fffe1f2c454] local_int_3: 4294967295   (0xFFFFFFFF)
==============================================================
[0x7fffe1f2c41c] local_int_1: 0   (0x00)
[0x7fffe1f2c420] local_int_2: -504183712   (0xE1F2C460)
[0x7fffe1f2c424] local_int_3: 32767   (0x7FFF)

*/