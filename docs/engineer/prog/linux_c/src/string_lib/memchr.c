原型：extern void *memchr(void *buf, char ch, unsigned count);

用法： #include<string.h>

    功能：从buf所指内存区域的前count个字节查找字符ch。

    说明：当第一次遇到字符ch时停止查找。如果成功，返回指向字符ch的指针；否则返回NULL。

    举例：

// memchr.c

#include <syslib.h>
#include <string.h>

    main()
{
  char *s = "Hello, Programmers!";
  char *p;

  clrscr();

  p = memchr(s, 'P', strlen(s));
  if (p)
    printf("%s", p);
  else
    printf("Not Found!");

  getchar();
  return 0;
}