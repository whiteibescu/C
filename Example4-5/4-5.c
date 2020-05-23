#include <stdio.h>

int main(void)
{
	int a = 10, b = 20, c = 10;
	int res;				// 결괏값을 저장할 변수
							// 각각 a와 b, c 값을 대입해보자.

	res = (a > b);
	printf("a > b : %d\n", res);
	res = (a >= b);
	printf("a >= b : %d\n", res);
	res = (a < b);
	printf("a < b : %d\n", res);
	res = (a <= b);
	printf("a <= b : %d\n", res);
	res = (a <= c);
	printf("a <= c : %d\n", res);
	res = (a == b);
	printf("a == b : %d\n", res);
	res = (a != c);
	printf("a != c : %d\n", res);

	return 0;
}