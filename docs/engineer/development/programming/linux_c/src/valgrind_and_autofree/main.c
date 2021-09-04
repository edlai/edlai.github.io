/*

Usage:

$ valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./executable exampleParam1

Example:

$ valgrind --leak-check=full ./a.out
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_LEAK_DEMO 1

#define autofree __attribute__((cleanup(free_stack)))

__attribute__((always_inline)) inline void free_stack(void *ptr) { free(*(void **)ptr); }

#if (MEM_LEAK_DEMO)
int non_autofree_test()
{
  int *i = malloc(sizeof(int));
  *i = 1;
  return *i;
}
#endif

int autofree_test()
{
  autofree int *i = malloc(sizeof(int));
  *i = 1;
  return *i;
}

int main(void)
{
  int r1 = autofree_test();
  printf("ret: %d\n", r1);

#if (MEM_LEAK_DEMO)
  int r2 = non_autofree_test();
  printf("ret: %d\n", r2);
#endif

  return 0;
}