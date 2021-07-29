// https://stackoverflow.com/questions/29203569/printing-function-address

// display function point

#include <stdio.h>
int test(int a, int b)
{
  return a + b;
}
int main(void)
{
  int (*ptr)(int, int);
  ptr = &test;
  printf("The address of the function is =%p\n", ptr);
  //printf("The address of the function pointer is =%p\n", &ptr);
  printf("The address of the function is =%p\n", test);
  return 0;
}