#include<stdio.h>
#include<string.h>
int main(){
    char url[100] = "http://see.xidian.edu.cn";
    char path[30] = "/cpp/u/biaozhunku/";
    strncat(url, path, 1000);  // 1000远远超过path的长度
    printf("%s\n", url);
    return  0;
}