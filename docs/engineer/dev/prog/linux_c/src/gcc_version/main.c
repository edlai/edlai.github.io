/*

C89/C90 -> C99 -> C11 -> C17/C18 -> C2x

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
#ifdef __STDC_VERSION__
    printf("__STDC_VERSION__ = %ld \n", __STDC_VERSION__);
#endif
#ifdef __STRICT_ANSI__
    puts("__STRICT_ANSI__");
#endif
    return 0;
}
