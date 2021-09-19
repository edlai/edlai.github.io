#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <ctype.h>

void initialize(double ***A, int r, int c)
{
  *A = (double **)malloc(sizeof(double *) * r);
  for (int i = 0; i < r; i++)
  {
    (*A)[i] = (double *)malloc(sizeof(double) * c);
    for (int j = 0; j < c; j++)
    {
      (*A)[i][j] = 0.0;
    }
  }
}

int main()
{
  double **A;
  initialize(&A, 10, 10);

  return 1;
}