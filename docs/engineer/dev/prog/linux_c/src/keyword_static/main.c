#include <stdio.h>

// this function only belong this scope
static int static_fun_demo()
{
  printf("static_fun_demo: this function only belong this scope\n");
  return 0;
}

int static_var_demo()
{
  static int a = 0;
  printf("a = %d\n", a++);

  return 0;
}

int main(void)
{

  static_fun_demo();
  for (int i = 0; i < 5; i++)
  {
    static_var_demo();
  }

  return 0;
}