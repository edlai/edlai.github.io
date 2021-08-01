#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
typedef union {
  uint32_t l;
  unsigned char c[4];
} EndianTest;

// 輸出位元組順序
void dump(uint32_t x) {
  EndianTest et;
  et.l = x;
  for (int i = 0; i < 4; i++) {
    printf("0x%02X ", et.c[i]);
  }
  printf("\n");
}

int main() {
  uint32_t x = 0x12345678;
  printf("0x%X unsigned integer hostlong：", x);
  dump(x);
  uint32_t n = htonl(x);
  printf("0x%X to network byte order：  ", x);
  dump(n);
}