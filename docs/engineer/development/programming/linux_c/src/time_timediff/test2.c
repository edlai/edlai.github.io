#include <stdio.h>
#include <time.h>
#include <unistd.h>  // sleep

int main()
{
  time_t start_t, end_t;
  double diff_t;

  printf("Starting of the program...\n");
  time(&start_t);

  printf("Sleeping for 5 seconds...\n");
  sleep(5);
  usleep(5000);

  time(&end_t);
  diff_t = difftime(end_t, start_t);

  printf("Execution time = %f\n", diff_t);
  printf("Exiting of the program...\n");

  return (0);
}