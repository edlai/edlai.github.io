#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse string and return revesed string
int reversing_string_with_tmp(char *str)
{

  printf("input string: %s\n", str);
  printf("input strlen: %ld\n", strlen(str));

  for (int i = 0; i < strlen(str) / 2; i++)
  {
    char tmp = str[i];
    str[i] = str[strlen(str) - 1 - i];
    str[strlen(str) - 1 - i] = tmp;

    printf("reversing: %c : %c\n", str[i], str[strlen(str) - 1 - i] );
  }
  printf("reversed: %s\n", str);
  return 1;
}

int reversing_string_without_tmp(char *str)
{

  printf("string: %s\n", str);
  printf("strlen: %ld\n", strlen(str));

  for (int i = 0; i < strlen(str) / 2; i++)
  {
    str[i] ^= str[strlen(str) - 1 - i];
    str[strlen(str) - 1 - i] ^= str[i];
    str[i] ^= str[strlen(str) - 1 - i];

    printf("reversing: %c : %c\n", str[i], str[strlen(str) - 1 - i] );
  }
  printf("reversed: %s\n", str);
  return 1;
}
// Driver Code
int main()
{

  char str1[] = "abcdefg";
  char str2[] = "hijklmn";
  reversing_string_with_tmp(str1);
  reversing_string_without_tmp(str2);

  return 0;
}