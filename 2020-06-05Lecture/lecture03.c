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

	// �ּ� -> �����
	(&t)->number = 2003;

	// ������ ������ �ּҴ�...
	struct _car* cp;
	cp = &t;
	cp->price = 2000.0;

	(*cp)/*�̸����Ŷ� ���� = p*/.number = 3003; 

	// ���� �򰥸��ٸ� -> �� ���� ���Ŷ�...



	return 0;
}