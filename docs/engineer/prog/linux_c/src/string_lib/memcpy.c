原型：extern void *memcpy(void *dest, void *src, unsigned int count);

  用法：#include <string.h>
  
  功能：由src所指内存区域复制count个字节到dest所指内存区域。
  
  说明：src和dest所指内存区域不能重叠，函数返回指向dest的指针。
  
  举例：

      // memcpy.c
      
      #include <syslib.h>
      #include <string.h>

      main()
      {
        char *s="Golden Global View";
        char d[20];
        
        clrscr();
        
        memcpy(d,s,strlen(s));
        d[strlen(s)]=0;
        printf("%s",d);

        getchar();
        return 0;
      }