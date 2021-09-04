// http://gundambox.github.io/2015/10/30/C%E8%AA%9E%E8%A8%80-struct%E3%80%81union%E3%80%81enum/

#include <stdio.h>

union Var{ 
    char ch;
    int num1;
    double num2;
}; 

int main(void) {
    
    union Var var = {'x'}; // 初始化只能指定第一個成員
    // union Var var = {123}; 這句是不行的

    printf("size of var = %ld\n", sizeof(var));    
    printf("var.ch = %c\n",var.ch); 
    printf("var.num1 = %d\n",var.num1); // 內容是無效的 
    printf("var.num2 = %.3f\n\n",var.num2); // 內容是無效的 
    
    var.num1 = 123;
    
    printf("size of var = %ld\n", sizeof(var));    
    printf("var.ch = %c\n",var.ch); // 內容是無效的 
    printf("var.num1 = %d\n",var.num1);
    printf("var.num2 = %.3f\n\n",var.num2); // 內容是無效的
    
    var.num2 = 456.789;
    
    printf("size of var = %ld\n", sizeof(var));    
    printf("var.ch = %c\n",var.ch); // 內容是無效的 
    printf("var.num1 = %d\n",var.num1); // 內容是無效的
    printf("var.num2 = %.3f\n\n",var.num2);
    
    return 0;
    
}
