#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ����� ������ ( ������ ) : ����ü : �������� ����
// �ݵ�� �ܿ� ��

/*
1.����ü�� ����
2.����ü�� ���� ����
3.����ü�� ���� �ȿ� ������� ó��

��� �����ϴ� ���
1. ������.�����
2. �����ͺ�����(�ּ�)->�����


*/
struct car {
	// member
	int code;
	char name[80];
	double price;
};

//#define Car struct car
// �ڷ������� ���� ���
typedef struct car Car; 


typedef struct car Car; {
	int code;
	char name[80];
	double price;
}CAR, UCAR, ICAR;

int main(void) {
	struct car ic;
	//����ü�� �̸��� ª�� �ٸ���  ����ϰ� �ʹ�...
	Car myCar;
	printf(" %d \n", sizeof(Car));
	printf(" %d \n", sizeof(myCar));
	// �⺻ ũ�� ���� : �ɹ����� ���� ���� ũ��

}





int main_01(void) {
	struct car myCar = { 1, "Grandure", 1000.10};
	// ����ü ������ �����Ѵ�...

	struct car uCar = myCar;
	
	printf("%p vs %p \n", myCar.name, uCar.name);
	printf("{%d, %s, %lf}\n",
		uCar.code, uCar.name, uCar.price);


	return 0;
}