#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    // 不可以聲明為 char *str = "http://c.biancheng.net";
    char str[] = "http://c.biancheng.net";
    memset(str, '-', 7);
    puts(str);
    system("pause");
    return EXIT_SUCCESS;
}