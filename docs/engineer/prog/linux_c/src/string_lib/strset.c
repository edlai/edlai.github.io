#include<stdio.h>
#include<string.h>
int main()
{
    char str[] = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char c = 'c';
    strset(str, c);
    printf("%s", str);
    return 0;
}