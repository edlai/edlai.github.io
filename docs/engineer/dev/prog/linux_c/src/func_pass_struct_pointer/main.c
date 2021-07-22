//https://stackoverflow.com/questions/10066709/passing-struct-pointer-to-function-in-c
// https://stackoverflow.com/questions/5060641/does-a-string-created-with-strcpy-need-to-be-freed
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct item
{
  char name[10];
  int age;
};

struct item *modify_item2(void)
{
  struct item *retVal = malloc(sizeof(struct item));
  strcpy(retVal->name, "Tom2");
  retVal->age = 5;
  return retVal;
}

void modify_item(struct item **s)
{
  struct item *retVal = malloc(sizeof(struct item));
  strcpy(retVal->name, "Tom");
  retVal->age = 10;

  *s = retVal;
}

int main()
{
  struct item *stuff = NULL;
  modify_item(&stuff);
  printf("Name: %s\n", stuff->name);
  printf("Age:  %d\n", stuff->age);

  // strcpy doesn't need to be freed
  // strcpy() doesn't create a string, it only copies a string. Memory allocation is completely separated from that process.
  //free(stuff->name);

  if (stuff)
  {
    free(stuff);
    stuff = NULL;
  }

  printf("==================================\n");
  struct item *stuff2 = NULL;
  stuff2 = modify_item2();
  printf("Name2: %s\n", stuff2->name);
  printf("Age2:  %d\n", stuff2->age);
  if (stuff2)
  {
    free(stuff2);
    stuff2 = NULL;
  }

  return 0;
}