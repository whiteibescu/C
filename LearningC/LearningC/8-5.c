#include <stdio.h>
#include <string.h>


int main(void)
{
	char str1[80] = "cat";
	char str2[80];

	strcpy_s(str1, 80, "tiger");
	strcpy_s(str2, 80, str1);
	printf("%s, %s\n", str1, str2);

	return 0;
}