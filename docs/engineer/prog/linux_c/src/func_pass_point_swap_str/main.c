// https://www.geeksforgeeks.org/swap-strings-in-c/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// BAD example: should be use double (**)
void swap(char *str1, char *str2)
{
  char *temp = str1;
  str1 = str2;
  str2 = temp;
}

// GOOD example: Swap Pointers
void swap1(char **str1_ptr, char **str2_ptr)
{
  char *temp = *str1_ptr;
  *str1_ptr = *str2_ptr;
  *str2_ptr = temp;
}

// GOOD example: Swap Data
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
  // TIP: below assigment equs to
  //      char *str1;
  //      char str[] = "geeks";
  //      *str = &str[0];
  //         0   1   2   3   4   5
  //       +---+---+---+---+---+---+
  //       | g | e | e | k | s | \0|
  //       +---+---+---+---+---+---+
  //  ex. 0xB00000000
  //       |
  //       +------------+
  //  str1 | 0xB00000000|
  //       +------------+
  //  ex. 0x00000006
  //

  char *str1 = "geeks";
  char *str2 = "forgeeks";

  printf("[%s():%d] Original: str1 is %s, str2 is %s\n", __func__, __LINE__, str1, str2);

  swap(str1, str2);
  printf("[%s():%d] BAD:      str1 is %s, str2 is %s\n", __func__, __LINE__, str1, str2);

  swap1(&str1, &str2);
  printf("[%s():%d] GOOD:     str1 is %s, str2 is %s\n", __func__, __LINE__, str1, str2);

  // TIP:
  //         0   1   2   3   4   5   6   7   8   9
  //       +---+---+---+---+---+---+---+---+---+---+
  //       | g | e | e | k | s | \0|   |   |   |   |
  //       +---+---+---+---+---+---+---+---+---+---+
  //  ex. 0x12345678
  char str3[10] = "geeks";
  char str4[10] = "forgeeks";

  swap2(str3, str4);
  printf("[%s():%d] str3 is %s, str4 is %s\n", __func__, __LINE__, str3, str4);

  //getchar();
  return 0;
}