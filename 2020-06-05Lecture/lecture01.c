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

int main(void) {
	struct car myCar = { 1, "Grandure", 1000.10};
	// 구조체 변수를 복사한다...

	struct car uCar = myCar;
	
	printf("%p vs %p \n", myCar.name, uCar.name);
	printf("{%d, %s, %lf}\n",
		uCar.code, uCar.name, uCar.price);


	return 0;
}