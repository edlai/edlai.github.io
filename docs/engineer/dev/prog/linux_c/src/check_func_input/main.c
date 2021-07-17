#include <stdio.h>
#include <stddef.h>
#include <string.h>

static int my_strncpy(char *destination, const char *source, size_t num)
{

  //printf("%d\n", (int)strlen(source));

  if (!destination || !*source || strlen(source) < num)
  { // < = better to check function input
    printf("error\n");
    return 0;
  }

  int count = 0;

  while (num-- && (*destination++ = *source++))
  {
    count++;
  }

  return count;
}

// Implement `strncpy()` function in C
int main(void)
{
  char *source = "12345678901234567890";
  char destination[21] = {0};

  printf("destination before: (%02ld) ", strlen(destination));
  for (int i = 0; i < 20; i++)
  {
    printf("%02X ", destination[i]);
  }
  printf("\n");

  size_t num = 6;

  if (num == my_strncpy(destination, source, num))
  {
    printf("destination after:  (%02ld) ", strlen(destination));
    for (int i = 0; i < 20; i++)
    {
      printf("%02X ", destination[i]);
    }
    printf("\n");
  }

  return 0;
}