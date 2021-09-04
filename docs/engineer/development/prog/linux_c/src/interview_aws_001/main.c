// http://www.sunshine2k.de/coding/c/mul32x32.html

/*
uint8_t:  0~2^8-1 (0x00~0xFF)
uint16_t: 0~2^16-1 (0x0000~0xFFFF)
uint32_t: 0~2^32-1 (0x00000000~0xFFFFFFFF)
uint64_t: 0~2^64-1 (0x0000000000000000~0xFFFFFFFFFFFFFFFF)

uint8  :  0 ~ 255
uint16 :  0 ~ 65535
uint32 :  0 ~ 4294967295
uint64 :  0 ~ 18446744073709551615
int8   :  -128 ~ 127
int16  :  -32768 ~ 32767
int32  :  -2147483648 ~ 2147483647
int64  :  -9223372036854775808 ~ 9223372036854775807


*/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

uint64_t mymul32x32(uint32_t a, uint32_t b)
{
  uint16_t va_high = (a >> 16) & 0xFFFF;
  uint16_t va_low = a & 0xFFFF;

  uint16_t vb_high = (b >> 16) & 0xFFFF;
  uint16_t vb_low = b & 0xFFFF;

  uint64_t mul_high_high = (uint64_t)((uint32_t)(va_high * vb_high)) << 32;
  uint64_t mul_high_low = (uint64_t)((uint32_t)(va_high * vb_low)) << 16;
  uint64_t mul_low_high = (uint64_t)((uint32_t)(va_low * vb_high)) << 16;
  uint32_t mul_low_low = (uint32_t)(va_low * vb_low);

  uint64_t res = 0;

  res = mul_high_high;
  res += mul_high_low;
  res += mul_low_high;
  res += mul_low_low;

  return res;
}

#if (0)
uint64_t mymul32x32_2(uint32_t a, uint32_t b)
{
  uint64_t result = (uint64_t)a * b;
  //uint32_t high = (result >> 32) && 0xffffffff;
  //uint32_t low = result && 0xffffffff;
  //printf("[expected] 0x%X * 0x%X =  0x%lX (%lu)\n", UINT32_MAX, UINT32_MAX, result, result);
  return result;
}
#endif

int main(void)
{
  uint64_t res = mymul32x32(UINT32_MAX, UINT32_MAX);
  //uint64_t res_2 = mymul32x32_2(UINT32_MAX, UINT32_MAX);

  printf("[result  ] 0x%X * 0x%X =  0x%lX (%lu)\n", UINT32_MAX, UINT32_MAX, res, res);
  //printf("[result 2] 0x%X * 0x%X =  0x%lX (%lu)\n", UINT32_MAX, UINT32_MAX, res_2, res_2);

  uint64_t expected = (uint64_t)UINT32_MAX * UINT32_MAX;

  printf("[expected] 0x%X * 0x%X =  0x%lX (%lu)\n", UINT32_MAX, UINT32_MAX, expected, expected);

  return 0;
}
