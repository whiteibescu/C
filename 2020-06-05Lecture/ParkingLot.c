#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// data ??? 여러 개의 데이터처리 시 반드시 하나를 지정하는 방법
struct _car {
	int number;
	double price;
	int in;
	int out;
	unsigned int in;
};
typedef struct _car Car;
// Car를 여러 개 저장(주차)해야하니까 배열을 사용
Car list[];
int hasEmpty(void)  {
	return 0;
}
int goHome() {
	
	time_t now = time(NULL);
	clock_t ct = clock();
	printf("%d \n", ct);
	
	return 0; //퇴근시간이다...
}
int main(void) {
	printf("//주차장입니다.... 저는 주차장 관리자입니다.\n");
	{
		do {
		
		printf("//차가 들어오고 있다...\n");
		printf("//주차장 내 빈 공간이 있다면?");
		if (hasEmpty()) {
			printf("주차할 수 있다...\n");
		}
		else {
			printf("// 빈 자리 나가세요\n");
		}

		printf("//차가 나가고 있다...\n");
		printf("// 요금내야죠~\n");
		printf("// 차가 나갔으니 빈 자리가 생겼다...\n");
	} while ( goHome());
	printf("// 퇴근 시간이 되어서 주차장 출입문 잠그고 집에 간다...\m");



	
}