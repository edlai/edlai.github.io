原型：extern int memcmp(void *buf1, void *buf2, unsigned int count);

用法： #include<string.h>

    功能：比较内存区域buf1和buf2的前count个字节。

    说明：
        当buf1<buf2时，返回值<0 当buf1 = buf2时，返回值 = 0 当buf1> buf2时，返回值> 0

    举例：

// memcmp.c

#include <syslib.h>
#include <string.h>

    main()
{
  char *s1 = "Hello, Programmers!";
  char *s2 = "Hello, programmers!";
  int r;

  clrscr();

  r = memcmp(s1, s2, strlen(s1));
  if (!r)
    printf("s1 and s2 are identical");
  else if (r < 0)
    printf("s1 less than s2");
  else
    printf("s1 greater than s2");

  getchar();
  return 0;
}
