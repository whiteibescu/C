#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// data ??? ���� ���� ������ó�� �� �ݵ�� �ϳ��� �����ϴ� ���
struct _car {
	int number;
	double price;
	int in;
	int out;
	unsigned int in;
};
typedef struct _car Car;
// Car�� ���� �� ����(����)�ؾ��ϴϱ� �迭�� ���
Car list[];
int hasEmpty(void)  {
	return 0;
}
int goHome() {
	
	time_t now = time(NULL);
	clock_t ct = clock();
	printf("%d \n", ct);
	
	return 0; //��ٽð��̴�...
}
int main(void) {
	printf("//�������Դϴ�.... ���� ������ �������Դϴ�.\n");
	{
		do {
		
		printf("//���� ������ �ִ�...\n");
		printf("//������ �� �� ������ �ִٸ�?");
		if (hasEmpty()) {
			printf("������ �� �ִ�...\n");
		}
		else {
			printf("// �� �ڸ� ��������\n");
		}

		printf("//���� ������ �ִ�...\n");
		printf("// ��ݳ�����~\n");
		printf("// ���� �������� �� �ڸ��� �����...\n");
	} while ( goHome());
	printf("// ��� �ð��� �Ǿ ������ ���Թ� ��װ� ���� ����...\m");



	
}