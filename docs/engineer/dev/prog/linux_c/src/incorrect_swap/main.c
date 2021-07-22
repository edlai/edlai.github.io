#include <stdio.h>
#include <limits.h>

// correct example to swap two values
void correct_swap(int *a, int *b)
{

  int tmp;

  printf("[%04d] a:%d, b=%d, tmp = %d\n", __LINE__, a, b, tmp);

  tmp = *a;
  printf("[%04d] a:%d, b=%d, tmp = %d\n", __LINE__, a, b, tmp);

  *a = *b;
  printf("[%04d] a:%d, b=%d, tmp = %d\n", __LINE__, a, b, tmp);

  *b = tmp;
  printf("[%04d] a:%d, b=%d, tmp = %d\n", __LINE__, a, b, tmp);
}

// incorrect example to swap two values
// http://arc2453.blog.fc2.com/blog-entry-31.html
void incorrect_swap(int *a, int *b)
{

  int tmp;

  printf("[%04d] a:%d, b=%d, tmp = %d\n", __LINE__, a, b, tmp);

  tmp = a;
  printf("[%04d] a:%d, b=%d, tmp = %d\n", __LINE__, a, b, tmp);

  a = b;
  printf("[%04d] a:%d, b=%d, tmp = %d\n", __LINE__, a, b, tmp);

  b = tmp;
  printf("[%04d] a:%d, b=%d, tmp = %d\n", __LINE__, a, b, tmp);
}

int main(void)
{
  int x = 10;
  int y = 20;

  incorrect_swap(&x, &y);
  printf("x= %d, y = %d\n", x, y);

  correct_swap(&x, &y);
  printf("x= %d, y = %d\n", x, y);

  return 0;
}