#include <stdio.h>

int main()
{
	int score[5];
	int i;
	int total = 0;
	double avg;

	for (i = 0; i < 5; ++i)
	{
		scanf_s("%d", &score[i], sizeof(score));
	}

	for (i = 0; i < 5; ++i)
	{
		total += score[i];
	}
	avg = total / 5.0;

	for (i = 0; i < 5; ++i)
	{
		printf("%d ", score[i]);
	}
	printf("\n");

	printf("ЦђБе : %.1lf\n", avg);

	return 0;
}