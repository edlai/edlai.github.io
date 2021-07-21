#include <stdio.h>

int global_var;

int main()
{
  int local_var;

  // check the value of global_var (always zero)
  printf("global_var: %d\n", global_var);

  // check the value of local_var (maybe non-zero)
  printf("local_var: %d\n", local_var);
  return 0;
}