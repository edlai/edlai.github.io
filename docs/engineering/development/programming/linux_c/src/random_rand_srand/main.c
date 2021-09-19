#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_test()

{
  int a;
  printf("The Random Number: ");
  for (int i = 0; i < 10; i++)
  {
    a = (rand() % 100) + 1;
    printf("%04d ", a);
  }
  printf(".\n");
}

void srand_test()
{
  int a;
  time_t t;
  printf("The Random Number: ");
  /* Intializes random number generator */
  srand((unsigned)time(&t));
  for (int i = 0; i < 10; i++)
  {
    a = (rand() % 100) + 1;
    printf("%04d ", a);
  }
  printf(".\n");
}

int main(void)
{

  printf("rand_test:  ");
  rand_test();
  printf("srand_test: ");
  srand_test();

  return 0;
}