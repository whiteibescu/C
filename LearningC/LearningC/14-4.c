#include <stdio.h>

int main(void)
{
	char animal[][10] = { "dog", "tiger", "rabbit", "horse", "cat" };

	for (int i = 0; i < 5; ++i)
	{
		printf("%s ", animal[i]);
	}

	return 0;
}