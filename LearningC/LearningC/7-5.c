#include <stdio.h>

void fruit();

int main()
{
	fruit();

	return 0;
}

void fruit(void)
{
	printf("apple\n");
	fruit();
}