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

    //deallocate the memory
    if (ptr)
    {
      free(ptr);
      ptr = NULL; // < = Aborted (core dumped) if uncomment this
    }
  }

  free(ptr); // < = this's OK if double free the point again
  return 0;
}