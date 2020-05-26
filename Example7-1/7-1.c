#include <stdio.h>

int sum(int x, int y);						// sum 함수 선언 : 186쪽에서 설명합니다.

int main(void)								// main 함수 시작
{
	int a = 10, b = 20;
	int result;

	result = sum(a, b);
	printf("result : %d\n", result);

	return 0;
}

int sum(int x, int y)
{
	int temp;

	temp = x + y;

	return temp;
}