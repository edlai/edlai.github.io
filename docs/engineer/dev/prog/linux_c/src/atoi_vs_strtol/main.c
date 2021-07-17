#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int atoi_val = 0;
  int strtol_val = 0;
  char str[20] = {0};
  char *endptr;

  strcpy(str, "98993489");
  atoi_val = atoi(str);
  printf("String value = %s, atoi() = %d, ", str, atoi_val);
  strtol_val = strtol(str, &endptr, 10);
  if (endptr > str)
  {
    printf("strtol() = %d\n", strtol_val);
  }
  else
  {
    printf("NOK\n");
  }

  strcpy(str, "abcde");
  atoi_val = atoi(str);
  printf("String value = %s, atoi() = %d, ", str, atoi_val);
  strtol_val = strtol(str, &endptr, 10);
  if (endptr > str)
  {
    printf("strtol() = %d\n", strtol_val);
  }
  else
  {
    printf("strtol() = NOK\n");
  }

  strcpy(str, "0");
  atoi_val = atoi(str);
  printf("String value = %s, atoi() = %d, ", str, atoi_val);
  strtol_val = strtol(str, &endptr, 10);
  if (endptr > str)
  {
    printf("strtol() = %d\n", strtol_val);
  }
  else
  {
    printf("NOK\n");
  }
}