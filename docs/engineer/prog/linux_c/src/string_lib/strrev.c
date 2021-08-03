#include<stdio.h>
#include<string.h>
int main()
{
    // 若改為 char *str1 = "abcxyz";，程序在運行時會崩潰
    char str1[] = "abcxyz";
    char *ret1 = strrev(str1);
    printf("The origin string of str1 is: %s\n", str1);
    printf("The reverse string of str1 is: %s\n", ret1);
    return 0;
}