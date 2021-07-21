#include <stdio.h>

int global_var_1;

int main()
{
  int local_var_1;
  int local_var_2;

  // check the value of global_var (the default value is zero)
  printf("global_var_1: %d\n", global_var_1);

  // check the value of local_var  (the default value is not always zero)
  printf("local_var_1: %d\n", local_var_1);
  printf("local_var_2: %d\n", local_var_2);

  return 0;
}