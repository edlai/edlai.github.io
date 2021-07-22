// https://blog.csdn.net/jasonchen_gbd/article/details/44044899
/*
$ apt-get install libcurl4-gnutls-dev

$ gcc -L/usr/lib/x86_64-linux-gnu -finstrument-functions main.c -o main

$ ./main

*/

// TODO: use timediff to check time consuming

#include <stdio.h>

#define DUMP(func, call) \
  printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)

void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *this_func, void *call_site)
{
  DUMP(this_func, call_site);
}

void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *this_func, void *call_site)
{
  DUMP(this_func, call_site);
}

int do_multi(int a, int b)
{
  return a * b;
}

int do_calc(int a, int b)
{
  return do_multi(a, b);
}

int main()
{
  int a = 4, b = 5;
  printf("result: %d\n", do_calc(a, b));
  printf("The address of the do_calc  is = %p\n", main);
  printf("The address of the do_calc  is = %p\n", do_calc);
  printf("The address of the do_multi is = %p\n", do_multi);
  return 0;
}

/*
__cyg_profile_func_enter: func = 0x55b58f9cf7b2, called by = 0x7f9645a27bf7
__cyg_profile_func_enter: func = 0x55b58f9cf763, called by = 0x55b58f9cf7eb
__cyg_profile_func_enter: func = 0x55b58f9cf71c, called by = 0x55b58f9cf794
__cyg_profile_func_exit: func = 0x55b58f9cf71c, called by = 0x55b58f9cf794
__cyg_profile_func_exit: func = 0x55b58f9cf763, called by = 0x55b58f9cf7eb
result: 20
__cyg_profile_func_exit: func = 0x55b58f9cf7b2, called by = 0x7f9645a27bf7
*/