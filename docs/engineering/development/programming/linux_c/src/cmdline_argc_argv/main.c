// a sample code to show argument count and variable
// https://blog.gtwang.org/programming/c-cpp-tutorial-argc-argv-read-command-line-arguments/
// https://blog.yiyu0x.org/2019/03/01/

#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("We have %d argument(s):\n", argc);
  for (int i = 0; i < argc; ++i)
  {
    printf("[%d] %s\n", i, argv[i]);
  }

 // the same 
  for (int i = 0; i < argc; ++i)
  {

    printf("[%d] %s \n", i, *(argv + i));
  }
  return 0;
}

/*

We have 3 argument(s):
[0] ./a.out
[1] hello
[2] world

*/