#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void char_alloc_demo()
{

  char *ptr;
  size_t length;

  length = 50;

  /* Allocate and zero memory for our string */
  ptr = (char *)calloc(length, sizeof(char));

  /* Check to see if we were successful */
  if (ptr == NULL)
  {

    printf("Could not allocate required memory\n");

    exit(1);
  }

  strcpy(ptr, "abcdefg");

  printf("ptr_value = %s,  ptr_address= %p \n", ptr, ptr);
  printf("sizeof(ptr)=%zu, strlen(ptr)=%zu \n", sizeof(ptr), strlen(ptr));

  for (int i = 0; i < strlen(ptr); i++)
  {
    printf("ptr + %d = (%p) %c\n", i, (ptr + i), *ptr + i);
  }

  free(ptr);
}


int main()
{
  char_alloc_demo();
  return 0;
}