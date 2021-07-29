#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 16
#endif

void hexdump(void *mem, unsigned int len)
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

int main(void)
{
  char str[] = "Hello World";
  char *p = str; // &str[0];
  short a;
  int b;
  long c;
  float d;
  double e;
  printf("%d %p\n", sizeof(str));

  // TIP: use *p to get
  printf("%c %d %d (0x%x) (%s)\n", *p, sizeof(*p), sizeof(p), p, p);

  printf("%d\n", sizeof(a));
  printf("%d\n", sizeof(b));
  printf("%d\n", sizeof(c));
  printf("%d\n", sizeof(d));
  printf("%d\n", sizeof(e));

  return 0;
}