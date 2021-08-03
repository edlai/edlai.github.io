#include<stdio.h>
#include<string.h>
int main(void){
    char* s1 = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char* s2 = "HTTP://see.xidian.edu.cn/cpp/u/xitong/";
    char* s3 = "abc";
    char* s4 = "abcxyz";
    char* s5 = "123456";
    char* s6 = "123";
    printf("s1-s2=%d\n", strncmp(s1, s2, 20));  // 是否区分大小写
    printf("s3-s4=%d\n", strncmp(s3, s4, 100));  // s3的长度小于s4
    printf("s5-s6=%d\n", strncmp(s5, s6, 100));  // s5的长度大于s6
    return 0;
}