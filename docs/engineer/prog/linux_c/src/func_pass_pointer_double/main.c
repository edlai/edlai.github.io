#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

// pass double point to a function
int my_strcpy(char **dest, char const *src, int len)
{
  // TIP: print the address
  printf("[%s: %d] destination (%p): %s\n", __func__, __LINE__, dest, *dest);

  // TIP: Initial memory allocation and assign its address to a variable
  char *p = calloc(0, sizeof(char) * (len + 1));       /* +1 for \0 */

  if (p == NULL)
    return 0;

  memcpy(p, src, len);

  // TIP: record to a variable
  *dest = p;
  printf("[%s: %d] destination (%p): %s\n", __func__, __LINE__, dest, *dest);

  return 1;
}

int main(void)
{
  char *source = "Hello, world! Hello, world! Hello, world! Hello, world!";
  char *destination = NULL;

  printf("[%s: %d] source      (%p): %s\n", __func__, __LINE__, source, source);
  printf("[%s: %d] destination (%p): %s\n", __func__, __LINE__, &destination, destination);

  if (my_strcpy(&destination, source, strnlen(source, UINT_MAX)))
    printf("[%s: %d] destination (%p): %s\n", __func__, __LINE__, &destination, destination);
  else
    fprintf(stderr, "[%s: %d] out of memory\n", __func__, __LINE__);

  // TIP: Deallocate allocated memory in main()
  if (destination)
  {
    free(destination);
    destination = NULL;
  }
  return 0;
}