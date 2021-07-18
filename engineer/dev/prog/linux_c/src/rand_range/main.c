#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Rules: random  number
1-10:       a=(rand() % 10) + 1
1-100:      a=(rand() % 100) + 1
100-1000:   a=(rand() % 901) +100
*/

void srand_test(int start_number, int end_number)
{
  int a;
  time_t t;
  int range = end_number - start_number + 1;

  printf("The Random Number: ");
  /* Intializes random number generator */
  srand((unsigned)time(&t));
  for (int i = 0; i < 10; i++)
  {
    a = (rand() % range) + start_number;
    printf("%04d ", a);
  }
  printf(".\n");
}

int main(void)
{


  printf("srand_test: 1~10:     ");
  srand_test(1, 10);
  printf("srand_test: 1~100:    ");
  srand_test(1, 100);
  printf("srand_test: 100~1000: ");
  srand_test(100, 1000);

  return 0;
}