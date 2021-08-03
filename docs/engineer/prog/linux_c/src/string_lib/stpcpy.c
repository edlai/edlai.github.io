#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N (10)
int main()
{
    char* p1 = "abcde";
    char* p2 = (char*)malloc(sizeof(char) * N);
    char* p3 = (char*)memcpy(p2, p1, N);
    printf("p2 = %s\np3 = %s\n", p2, p3);
    free(p2);
    p2 = NULL;
    p3 = NULL;
    system("pause");
    return 0;
}