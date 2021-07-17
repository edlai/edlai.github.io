#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void str_2_int(char *str)
{
  int atoi_val = 0;
  int strtol_val = 0;
  char *endptr = NULL;

  atoi_val = atoi(str);
  printf("String value = %10s, atoi() = %10d, ", str, atoi_val);
  strtol_val = strtol(str, &endptr, 10);
  if (endptr > str)
  {
    printf("strtol() = %10d\n", strtol_val);
  }
  else
  {
    printf("%s\n", "<NOK>");
  }
}

int main(void)
{

  str_2_int("98993489");
  str_2_int("-98993489");
  str_2_int("-98993.489");
  str_2_int("abc12345");
  str_2_int("0");
}