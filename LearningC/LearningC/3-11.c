#include <stdio.h>

int main(void)
{
	char grade;
	char name[20];	

	printf("학점 입력 : ");
	scanf_s("%c", &grade, sizeof(grade));
	printf("이름 입력 : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s의 학점은 %c입니다.\n", name, grade);

	return 0;
}