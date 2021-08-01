// NOK, should be do add2line, but this code cannot do so now, need to be refixed.

// gcc -O0 -rdynamic -finstrument-functions main.c -ldl -o main

// ./main 3>&1

#define _GNU_SOURCE
#include <dlfcn.h>

#include <stdlib.h>
#include <stdio.h>

#define TRACE_FD 3

#define DUMP(func, call) \
        printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)

void __attribute__((__no_instrument_function__))
__cyg_profile_func_enter(void *this_func, void *call_site)
{
  static FILE* trace = NULL;
  Dl_info info;

  if(trace == NULL) {
    trace = fdopen(TRACE_FD, "w");

    if(trace == NULL) abort();

    setbuf(trace, NULL);
  }

  if(dladdr(this_func, &info))
    fprintf(trace, "%p [%s] %s\n",
            this_func,
            info.dli_fname ? info.dli_fname : "?",
            info.dli_sname ? info.dli_sname : "?");
}


void __attribute__((__no_instrument_function__))
__cyg_profile_func_exit(void *this_func, void *call_site)
{
  DUMP(this_func, call_site);
}

int main(void)
{
  puts("Hello World!");
  return 0;
}