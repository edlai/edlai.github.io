#include <stdio.h>
#include <string.h>
int main(void)
{
    /*定義兩個字符串*/
    char *s1 = "http://see.xidian.edu.cn/cpp/u/biaozhunku/";
    char *s2 = "http://see.xidian.edu.cn/cpp/shujujiegou/";
    /*比較字符串（不分大小寫）*/
#if (0)
    int result = stricmp(s1, s2); // 也可以改成strcmpi()
    if (result > 0)
    {
        printf("Result: s1 > s2");
    }
    else if (result < 0)
    {
        printf("Result: s1 < s2");
    }
    else if (result == 0)
    {
        printf("Result: s1 = s2");
    }
    getchar(); /*等待用戶輸入個字符，然後退出*/
#endif
    return 0;
}