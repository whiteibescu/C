#include <stdio.h>

int sum(int x, int y);

int main(void)
{
	int a = 10, b = 20;
	int result;

	result = sum(a, b);
	printf("result : %d\n", result);

	return 0;
}