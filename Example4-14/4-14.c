#include <stdio.h>

int main(void)
{
	int a = 10, b = 5;
	int res;

	res = a / b * 2;			//우선 순위가 같으므로 왼쪽으로부터 차례로 연산
	printf("res = %d\n", res);
	res = ++a * 3;
	printf("res = %d\n", res);
	res = a > b && a != 5;
	printf("res = %d\n", res);
	res = a % 3 == 0;
	printf("res = %d\n", res);

	return 0;
}