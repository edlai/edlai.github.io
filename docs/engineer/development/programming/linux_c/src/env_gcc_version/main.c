// https://ubuntuqa.com/zh-tw/article/10432.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

#ifdef __STDC_VERSION__
  printf("__STDC_VERSION__ = %ld \n", __STDC_VERSION__);
#endif
#ifdef __STRICT_ANSI__
  puts("__STRICT_ANSI__");
#endif

  return 0;
}
