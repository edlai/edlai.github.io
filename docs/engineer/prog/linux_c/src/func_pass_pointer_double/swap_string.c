#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *str1, char *str2)
{
  char *temp = str1;
  str1 = str2;
  str2 = temp;
}  
void swap1(char **str1_ptr, char **str2_ptr)
{
  char *temp = *str1_ptr;
  *str1_ptr = *str2_ptr;
  *str2_ptr = temp;
}  

/* Swaps strings by swapping data*/
void swap2(char *str1, char *str2)
{
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}  
   

int main()
{
  char *str1 = "geeks";
  char *str2 = "forgeeks";

  printf("str1 is %s, str2 is %s\n", str1, str2);

  swap(str1, str2);
  printf("str1 is %s, str2 is %s\n", str1, str2);

  swap1(&str1, &str2);
  printf("str1 is %s, str2 is %s\n", str1, str2);

  char str3[10] = "geeks";
  char str4[10] = "forgeeks";
  swap2(str3, str4);
  printf("str3 is %s, str4 is %s\n", str3, str4);

  //getchar();
  return 0;
}