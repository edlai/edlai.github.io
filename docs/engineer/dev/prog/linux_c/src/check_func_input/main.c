#include <stdio.h>
#include <stddef.h>
#include <string.h>

static int my_strncpy(char *destination, const char *source, size_t num)
{

  //printf("%d\n", (int)strlen(source));

  if (!destination || !*source)
  {
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

int main(void)
{
  char *source = "12345678901234567890";
  
  // < = better to empty array using {0}. not {'\0'}  to save running time
  char destination[21] = {0};

  printf("destination before: (0x%p)(%02ld) ", destination, strlen(destination));
  for (int i = 0; i < 20; i++)
  {
    printf("%02X ", destination[i]);
  }
  printf("\n");

  size_t num = 6;

  if (num == my_strncpy(destination, source, num))
  {
    printf("destination after:  (0x%p)(%02ld) ", destination, strlen(destination));
    for (int i = 0; i < 20; i++)
    {
      printf("%02X ", destination[i]);
    }
    printf("\n");
  }

  return 0;
}