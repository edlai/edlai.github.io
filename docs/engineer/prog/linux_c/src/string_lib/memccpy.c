原型：extern void *memccpy(void *dest, void *src, unsigned char ch, unsigned int count);

用法： #include<string.h>

    功能：由src所指內存區域復制不多於count個字節到dest所指內存區域，如果遇到字符ch則停止復制。

    說明：返回指向字符ch後的第一個字符的指針，如果src前n個字節中不存在ch則返回NULL。ch被復制。

    舉例：

// memccpy.c

#include <syslib.h>
#include <string.h>

    main()
{
  char *s = "Golden Global View";
  char d[20], *p;

  clrscr();

  p = memccpy(d, s, 'x', strlen(s));
  if (p)
  {
    *p = '\0'; // MUST Do This
    printf("Char found: %s.\n", d);
  }
  else
    printf("Char not found.\n");

  getchar();
  return 0;
}
