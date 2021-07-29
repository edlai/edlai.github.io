// dump function enter and exit

/* https://blog.csdn.net/jasonchen_gbd/article/details/44044899
$ gcc -L/usr/lib/x86_64-linux-gnu -finstrument-functions main.c -o main
$ ./main
*/

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

int main(void)
{
  int a = 4, b = 5;
  printf("result: %d\n", do_calc(a, b));

  // TIP: print function point in the code (both main and &main are OK) if no add2line from toolchain
  printf("The address of main:               %p %p\n", main,     &main);
  printf("The address of do_calc  function:  %p %p\n", do_calc,  &do_calc);
  printf("The address of do_multi function:  %p %p\n", do_multi, &do_multi);

  return 0;
}

/*
__cyg_profile_func_enter: func = 0x563dc8e847b2, called by = 0x7f32fdfe2bf7
__cyg_profile_func_enter: func = 0x563dc8e84763, called by = 0x563dc8e847eb
__cyg_profile_func_enter: func = 0x563dc8e8471c, called by = 0x563dc8e84794
__cyg_profile_func_exit: func = 0x563dc8e8471c, called by = 0x563dc8e84794
__cyg_profile_func_exit: func = 0x563dc8e84763, called by = 0x563dc8e847eb
result: 20
The address of main:               0x563dc8e847b2 0x563dc8e847b2
The address of do_calc  function:  0x563dc8e84763 0x563dc8e84763
The address of do_multi function:  0x563dc8e8471c 0x563dc8e8471c
__cyg_profile_func_exit: func = 0x563dc8e847b2, called by = 0x7f32fdfe2bf7
*/