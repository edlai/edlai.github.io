#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

int isNumber(char s[])
{
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (isdigit(s[i]) == 0)
      return 0;
  }
  return 1;
}

int main()
{
  char test_num[][10] = {"123", "-123", "123.22", "-123.22"};

  for (int i = 0; i < 4; i++)
  {
    if (isNumber(test_num[i]))
    {
      printf("%s is a number\n", test_num[i]);
    }
    else
    {
      printf("%s is not a number\n", test_num[i]);
    }
  }
}