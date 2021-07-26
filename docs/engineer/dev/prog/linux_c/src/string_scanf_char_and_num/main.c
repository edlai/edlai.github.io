//https://stackoverflow.com/questions/12909840/using-scanf-to-read-a-string-and-an-int-separated-by

#include <stdio.h>
int main (void) {
    char str[20] = {'\0'};
    int count, num = 42;

    count = sscanf ("hello/17", "%[^/]/%d", str, &num);

    printf ("String was '%s'\n", str);
    printf ("Number was %d\n", num);
    printf ("Count  was %d\n", count);

    return 0;
}