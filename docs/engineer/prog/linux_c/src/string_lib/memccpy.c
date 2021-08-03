/*

extern void *memccpy(void *dest, void *src, unsigned char ch, unsigned int count);

*/

// memccpy.c

#include <stdio.h>
#include <string.h>

int main(void)
{
  char *src = "Hello World!!!";
  char dest[20], *p;

  p = memccpy(dest, src, 'W', strlen(src));
  if (p)
  {
    *p = '\0';                            // MUST Do This
    printf("Char found: %s.\n", dest);
  }
  else
    printf("Char not found.\n");

  return 0;
}
