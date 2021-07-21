#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <ctype.h>

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 16
#endif

void my_hexdump(void *mem, unsigned int len)
{
  unsigned int i, j;

  for (i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++)
  {
    /* print offset */
    if (i % HEXDUMP_COLS == 0)
    {
      printf("0x%06x: ", i);
    }

    /* print hex data */
    if (i < len)
    {
      printf("%02x ", 0xFF & ((char *)mem)[i]);
    }
    else /* end of block, just aligning for ASCII dump */
    {
      printf("   ");
    }

    /* print ASCII dump */
    if (i % HEXDUMP_COLS == (HEXDUMP_COLS - 1))
    {
      for (j = i - (HEXDUMP_COLS - 1); j <= i; j++)
      {
        if (j >= len) /* end of block, not really printing */
        {
          putchar(' ');
        }
        else if (isprint(((char *)mem)[j])) /* printable char */
        {
          putchar(0xFF & ((char *)mem)[j]);
        }
        else /* other char */
        {
          putchar('.');
        }
      }
      putchar('\n');
    }
  }
}

// pass double point to a function
int my_strcpy(char **dest, char const *src, int len)
{

  printf("destination (%p): %s\n", dest, *dest);

  char *p = calloc(0, sizeof(char) * (len + 1)); /* +1 for \0 */

  if (p == NULL)
    return 0;

  //strncpy(p, src, len + 1);
  for (int i = 0; i < len + 1; i++)
  {
    *(p + i) = *(src + i);
    printf("%02d [%p] %02X %c\n", i, p + i, *(p + i), *(p + i));
  }

  *dest = p;

  my_hexdump((void *)src, len);

  return 1;
}

int main(void)
{
  char *source = "Hello, world! Hello, world! Hello, world! Hello, world!";
  // sachar *destination; destination = NULL;
  char *destination = NULL;

  printf("source      (%p): %s\n", source, source);
  printf("destination (%p): %s\n", &destination, destination);

  if (my_strcpy(&destination, source, strnlen(source, UINT_MAX)))
    printf("destination (%p): %s\n", &destination, destination);
  else
    fprintf(stderr, "out of memory\n");

  if (destination)
  {
    free(destination);
    destination = NULL;
  }
  return 0;
}