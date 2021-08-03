// C program to illustrate  
// the strnset() function 
  
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[] = "GeeksforGeeks"; 
      
    printf("Original String:%s\n", str); 
      
    // First 5 character of string str 
    // replaced by character '*' 
    // printf("Modified String:%s\n", strnset(str, '*', 5)); 
      
    return 0; 
}