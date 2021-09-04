// https://jaime-lin.medium.com/%E8%81%AF%E7%99%BC%E7%A7%91-c%E8%AA%9E%E8%A8%80%E6%B8%AC%E8%A9%A6%E9%A1%8C%E7%9B%AE-7097f09add02

#include <stdio.h>

int c;

int func(int n){
    c *= n;
    return n;
}

int main(void) {
	c = 1;
	int n = 2;
	func(func(func(func(func(func(func(func(n)))))))); //c = 256
	printf("c = %d", c); // 37
	return 0;
}