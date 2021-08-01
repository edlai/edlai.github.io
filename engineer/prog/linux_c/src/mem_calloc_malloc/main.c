#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int malloc_demo()
{
  int *dynArr;

  int arrLen = 5;

  dynArr = (int *)malloc(arrLen * sizeof(int));

  if (dynArr == NULL)
  {
    fprintf(stderr, "Error: unable to allocate required memory\n");
    return 1;
  }

  for (int i = 0; i < arrLen; ++i)
  {
    dynArr[i] = 0x5A;
    printf("(%p) 0x%02X \n", dynArr + i, dynArr[i]);
  }
  printf("\n");
  free(dynArr);
}

int calloc_demo()
{
  int *dynArr;

  int arrLen = 5;

  dynArr = (int *)calloc(1, arrLen * sizeof(int));

  if (dynArr == NULL)
  {
    fprintf(stderr, "Error: unable to allocate required memory\n");
    return 1;
  }

  for (int i = 0; i < arrLen; ++i)
  {
    dynArr[i] = 0xA5;
    printf("(%p) 0x%02X \n", dynArr + i, dynArr[i]);
  }

  printf("\n");
  free(dynArr);
}



int main(void)
{

  malloc_demo();
  calloc_demo();

  //memset
  //realloc

  return 0;
}