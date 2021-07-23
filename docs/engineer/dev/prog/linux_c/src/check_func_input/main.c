#include <stdio.h>
#include <stddef.h>
#include <string.h>

static int my_strncpy(char *destination, const char *source, size_t num)
{

  //printf("%d\n", (int)strlen(source));

  // TIP: confirm inputs are not null
  if ( !source || !*source)
  {
    printf("source: %p\n", source);
    printf("input error\n");
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
  //char *source = "01234567890123456789";
  //char *source = NULL;
  char *source;

  // TIP: use {0} to empty ({'\0'} is OK but to save running time
  char destination[21] = {0};

  printf("                                           ");
  for (int i = 0; i <= 20 ; i++)
  {
    printf("%02d ", i + 1 );
  }
  printf("\n");

#if (0)
  printf("source            : (0x%p)(%02ld) ", source, strlen(source));
  for (int i = 0; i <= strlen(source) ; i++)
  {
    printf("%02X ", source[i]);
  }
  printf("\n");
#endif

  printf("destination before: (0x%p)(%02ld) ", destination, strlen(destination));
  for (int i = 0; i < 21; i++)
  {
    printf("%02X ", destination[i]);
  }

  printf("\n");

  // TIP: confirm
  size_t num = 6;

  if (num == my_strncpy(destination, source, num))
  {
    printf("destination after:  (0x%p)(%02ld) ", destination, strlen(destination));
    for (int i = 0; i < 21; i++)
    {
      printf("%02X ", destination[i]);
    }
    printf("\n");
  }

  return 0;
}