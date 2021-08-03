#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char* s1 = "http://c.biancheng.net/cpp/u/biaozhunku/";
    char* s2 = "c is good";
    int n = strcspn(s1,s2);
    printf("The first char both in s1 and s2 is :%c\n",s1[n]);  
    printf("The position in s1 is: %d\n",n);
    system("pause");
    return 0;
}