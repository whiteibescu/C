#include <stdio.h>

void fruit(void);

int main()
{
	fruit(1);

	return 0;
}

void fruit(int count)
{
	printf("apple\n");
	if (count == 3)
		return;
	fruit(count + 1);
}

