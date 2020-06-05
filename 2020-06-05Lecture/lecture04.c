#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _car {
	int number;
	double price;
};
typedef struct _car Car;
typedef struct _car* PCar;
typedef struct _car ACar[12];

int main(void) {
	ACar list;
	PCar now = &list[0];
	Car temp;

	temp = list[0];
	temp.number = 11;
	temp.price = 1000.0;
	
	printf("%d, %lf\n", now->number, now->price);

	return 0;
}