// https://www.runoob.com/cprogramming/c-fun-pointer-callback.html

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// pass callback function
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
  for (size_t i = 0; i < arraySize; i++)
    array[i] = getNextValue();
}

// Get random value
int getNextRandomValue(void)
{
  int a;
  a = rand() % 100 + 1;
  return a;
}

int main(void)
{
  int myarray[10] = {0};

  // TIP: srand in main not in function
  srand(time(NULL));

  // normally function call
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", getNextRandomValue());
  }

  printf("\n");

  // TIP: pass getNextRandomValue as function point to populate_array function
  populate_array(myarray, 10, getNextRandomValue);

  for (int i = 0; i < 10; i++)
  {
    printf("%d ", myarray[i]);
  }

  printf("\n");
  return 0;
}