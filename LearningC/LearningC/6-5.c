#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;

	for (i = 1; i <= 10; ++i)
	{
		sum = +i;
		if (sum > 30)
			break;
	}

	printf("������ �� : %d\n", sum);
}