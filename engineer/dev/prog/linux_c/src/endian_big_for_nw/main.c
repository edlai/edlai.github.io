#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
typedef union {
  uint32_t l;
  unsigned char c[4];
} EndianTest;

// 輸出位元組順序
void printBytes(uint32_t x) {
  EndianTest et;
  et.l = x;
  for (int i = 0; i < 4; i++) {
    printf("0x%02X ", et.c[i]);
  }
  printf("\n");
}

int main() {
  uint32_t x = 0x12345678;
  printf("0x%X 在記憶體中的儲存順序：", x);
  printBytes(x);
  uint32_t n = htonl(x);
  printf("0x%X 在網路中的傳輸順序：  ", x);
  printBytes(n);
}