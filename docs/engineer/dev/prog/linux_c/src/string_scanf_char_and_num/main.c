//https://stackoverflow.com/questions/12909840/using-scanf-to-read-a-string-and-an-int-separated-by

#include <stdio.h>

int main(void)
{
    char str[20] = {'\0'};
    int count, num = 42;

    // TIPS: use %[^/] to grab the string
    count = sscanf("hello/17", "%[^/]/%d", str, &num);

    printf("String was '%s'\n", str);
    printf("Number was %d\n", num);
    printf("Count  was %d\n", count);

    char sentence[] = "Rudolph is 12 years old";
    char str2[20];
    int i;

    // TIPS: use %*s to by-pass the unnecessary string
    sscanf(sentence, "%s %*s %d", str, &i);
    printf("%s -> %d\n", str, i);

    return 0;
}