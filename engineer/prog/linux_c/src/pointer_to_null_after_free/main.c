#include <stdio.h>
#include <stdlib.h>

#define NUM 10

int main()
{
  int *ptr, sum = 0;

  //allocate dynamic memory
  ptr = malloc(NUM * sizeof(int));

  //if success
  if (ptr != NULL)
  {
    int i = 0;
    //get input from the user
    for (i = 0; i < NUM; i++)
      *(ptr + i) = (rand() % 10) + 1;

    //add all elements
    for (i = 0; i < NUM; i++)
      sum += *(ptr + i);

    printf("numbers:");
    for (i = 0; i < NUM; i++)
      printf(" %d", *(ptr + i));
    printf("\n");

    //print the result
    printf("sum = %d\n", sum);

    // confirm the point address is not empty before deallocating the memory
    if (ptr)
    {
      // deallocating the memory
      free(ptr);
      // point to NULL
      ptr = NULL;
    }
  }

  // it will not cause segmentation fault if double free the point again
  free(ptr);
  return 0;
}