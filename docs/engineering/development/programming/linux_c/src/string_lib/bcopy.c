// bcopy.c

/*
void bcopy( const void *src,
            void *dst,
            size_t n );
*/

// https://doc.bccnsoft.com/docs/cfuncs/string/bcopy.html

#include <stdio.h>
#include <strings.h>


int main(void)
{
  char *src = "Hello World!!!";
  char dest[20] = {0};             // clean the dest

  bcopy(src, dest, 10);
  printf("src:  %s\n", src);
  printf("dest: %s\n", dest);

  bzero(dest, 20);
  bcopy(src + 6, dest, 5);
  printf("New Dest: %s\n", dest);

  return 0;
}