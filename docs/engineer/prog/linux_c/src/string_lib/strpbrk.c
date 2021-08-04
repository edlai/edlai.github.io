#include <stdio.h>
#include <string.h>

int main()
{
  const char str1[] = "Hello, World!!!";
  const char str2[] = "W";
  char *ret;

  ret = strpbrk(str1, str2);
  if (ret)
  {
    printf("First matching character: %c\n", *ret);
    printf("All matching character: %s\n", ret);
  }
  else
  {
    printf("Character not found\n");
  }

  return (0);
}