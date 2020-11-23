#include <stdio.h>


int main(void)
{
	char ch;
	int i;

	for (i = 0; i < 3; ++i)
	{
		scanf_s("%c", &ch, sizeof(ch));
		printf("%c", ch);
	}
}