// https://unix.stackexchange.com/questions/120380/what-c-library-version-does-my-system-use

#include <gnu/libc-version.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

  printf("%s %s\n", gnu_get_libc_version(), gnu_get_libc_release());
  printf("glibc v%i %i.%i\n", __GNU_LIBRARY__, __GLIBC__, __GLIBC_MINOR__);

  return 0;
}