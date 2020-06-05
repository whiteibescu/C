#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _car{
	int number;
	double price;
};


int main(void)
{
	struct _car t;
	t.number = 1003;
	t.price = 1000.0;

	// 주소 -> 멤버명
	(&t)->number = 2003;

	// 포인터 변수는 주소다...
	struct _car* cp;
	cp = &t;
	cp->price = 2000.0;

	(*cp)/*이름쓴거랑 같다 = p*/.number = 3003; 

	// 만약 헷갈린다면 -> 를 많이 쓰셔라...



	return 0;
}