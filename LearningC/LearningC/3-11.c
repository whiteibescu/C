#include <stdio.h>

int main(void)
{
	char grade;
	char name[20];	

	printf("���� �Է� : ");
	scanf_s("%c", &grade, sizeof(grade));
	printf("�̸� �Է� : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s�� ������ %c�Դϴ�.\n", name, grade);

	return 0;
}