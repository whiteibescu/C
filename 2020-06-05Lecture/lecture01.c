#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 사용자 정의형 ( 복합형 ) : 구조체 : 변수들의 모음
// 반드시 외울 것

/*
1.구조체형 정의
2.구조체형 변수 선언
3.구조체형 변수 안에 멤버들을 처리

멤버 접근하는 방법
1. 변수명.멤버명
2. 포인터변수명(주소)->멤버명


*/
struct car {
	// member
	int code;
	char name[80];
	double price;
};

//#define Car struct car
// 자료형명을 새로 등록
typedef struct car Car; 


typedef struct car Car; {
	int code;
	char name[80];
	double price;
}CAR, UCAR, ICAR;

int main(void) {
	struct car ic;
	//구조체형 이름을 짧게 다르게  사용하고 싶다...
	Car myCar;
	printf(" %d \n", sizeof(Car));
	printf(" %d \n", sizeof(myCar));
	// 기본 크기 계산법 : 맴버들의 총합 보다 크다

}





int main_01(void) {
	struct car myCar = { 1, "Grandure", 1000.10};
	// 구조체 변수를 복사한다...

	struct car uCar = myCar;
	
	printf("%p vs %p \n", myCar.name, uCar.name);
	printf("{%d, %s, %lf}\n",
		uCar.code, uCar.name, uCar.price);


	return 0;
}