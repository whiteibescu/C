#include <stdio.h>

int main(void)
{
	int a = 10, b = 20, c = 10;
	int res;				// �ᱣ���� ������ ����
							// ���� a�� b, c ���� �����غ���.

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