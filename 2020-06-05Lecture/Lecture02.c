#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _rgb_color {
	
	unsigned char blue : 2;
	unsigned short green : 4;
	unsigned char red : 2;
}RGB;
typedef struct _bits {
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
}BITS;
// 비트 필드 구조체

// 자료구조 ??? 자기 참조 구조체
struct _node {
	int data;
	struct _ node* prev;
	struct _ node* next;
};

int main(void) {
	printf(" %d \n", sizeof(RGB));
}