#define clrscr()            \
  do                        \
  {                         \
    printf("\033[H\033[J"); \
  } while (0)