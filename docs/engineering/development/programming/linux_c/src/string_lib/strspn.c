#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    int i;
    char str[] = "129th";
    char accept[] = "1234567890";
    i = strspn(str, accept);
    printf("str 前 %d 個字符都屬於 accept\n",i);
    system("pause");
    return 0;
}