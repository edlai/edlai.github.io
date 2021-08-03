// https://xiwan.io/archive/string-split-strtok-strtok-r-strsep.html

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    const char * const str = "MAC-:00-1C-42-A7-F1-D9";
    const char * const delim = "-:";
    char buf[30] = {0};
    char *substr = NULL;
    int count = 0;

    strcpy(buf, str);
    printf("original string: %s (@%p)\n", buf, buf);

    substr = strtok(buf, delim);
    do {
        printf("#%d sub string: %s (@%p)\n", count++, substr, substr);
        substr = strtok(NULL, delim);
    } while (substr);

    printf("original string after 'strtok': ");
    for (count = 0; count < strlen(str); count++) {
        printf("%c", buf[count]?:'*');
    }
    printf(" (@%p)\n", buf);

    return 0;
}