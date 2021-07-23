#include <stdio.h>

// TIP: union
typedef union
{
  unsigned long l;
  unsigned char c[4];
} EndianTest;

int main(void)
{
  EndianTest et;
  et.l = 0x12345678;

  printf("本系統位元組順序為：");

  if (et.c[0] == 0x78 && et.c[1] == 0x56 && et.c[2] == 0x34 && et.c[3] == 0x12)
  {
    printf("Little Endian\n");
  }
  else if (et.c[0] == 0x12 && et.c[1] == 0x34 && et.c[2] == 0x56 && et.c[3] == 0x78)
  {
    printf("Big Endiann");
  }
  else
  {
    printf("Unknown Endian\n");
  }

  printf("0x%lX 在記憶體中的儲存順序：\n", et.l);
  for (int i = 0; i < 4; i++)
  {
    printf("%p : 0x%02X\n", &et.c[i], et.c[i]);
  }

  return 0;
}