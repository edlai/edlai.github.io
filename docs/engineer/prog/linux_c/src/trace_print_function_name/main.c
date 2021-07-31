// https://www.codenong.com/cs106497648/
// https://stackoverflow.com/questions/1644868/define-macro-for-debug-printing-in-c

// an example of using debug MACRO

#include <stdio.h>
#include <time.h>

#define DEBUG        /* comment this to disable Debug Message */

// #line 206         /* Uncomment this to redeinfe LINE number */

#ifdef DEBUG
#define debug_print(fmt, ...) \
        do { fprintf(stderr, "[%lu | %s:%d:%s()] " fmt, time(0), __FILE__, __LINE__, __func__, __VA_ARGS__); } while (0)
#else
#define debug_print(fmt, ...)
#endif

void silly_function(void)
{
  debug_print("%s\n", "Here I am");
}

int main(void)
{
  debug_print("%s\n", "Here I am");
  silly_function();

  return 0;
}