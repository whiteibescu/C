#include <stdio.h>

int main(void)
{
	int num, grade;

	printf("�й� �Է� : ");
	scanf_s("%d", &num, sizeof(int));
	getchar();
	printf("���� �Է� : ");
	grade = getchar();
	printf("�й� : %d, ����: %c", num, grade);

	return 0;
}