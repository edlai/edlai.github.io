// https://skylinelimit.blogspot.com/2018/02/c-2.html

#include <stdio.h>
#include <string.h>

int main(void)
{
  int i = 67; // ASCII 的 'C'
  char s[8] = "Hi 1234";
  printf("address of i: %p\naddress of s: %p\n", &i, s);
  strncpy(s, "hello sky", 8);
  printf("(1) value of s: %s\nvalue of i: %d\n", s, i); // s: hello skC, i: 67
  s[7] = '\0';                                          // 自己補 '\0'
  printf("(2) value of s: %s\n", s);                    //  s: hello s

  return 0;
}