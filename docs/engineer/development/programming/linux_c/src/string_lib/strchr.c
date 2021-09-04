#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *s = "0123456789012345678901234567890";
    char *p;
    p = strchr(s, '5');
    printf("%ld\n", s);
    printf("%ld\n", p);
    system("pause");
    return 0;
}