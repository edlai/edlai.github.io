#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void str_2_int(char *str)
{
  int atoi_val = 0;
  int strtol_val = 0;
  char *endptr = NULL;

  printf("String value = %10s, ", str);

  atoi_val = atoi(str);
  printf("atoi() = %10d, ", atoi_val);

  strtol_val = strtol(str, &endptr, 10);
  if (endptr > str)
  {
    printf("strtol() = %10d ", strtol_val);
  }
  else
  {
    printf("strtol() = %10s", "<NOK> ");
  }

  printf("(str: %p, endptr: %p)", str, endptr);
  printf("\n");
}

int main(void)
{

  str_2_int("98993489");
  str_2_int("-98993489");
  str_2_int("-98993.489");
  str_2_int("abc12345");
  str_2_int("12345abc");
  str_2_int("1a2b3c4d");
  str_2_int("0");
}