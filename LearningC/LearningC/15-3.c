#include <stdio.h>

void print_str(char** pps, int cnt);

int main(void)
{
	char* pty_ary[] = { "eagle", "tiger", "lion", "squirrel" };
	int count;

	count = sizeof(pty_ary) / sizeof(pty_ary[0]);
	print_str(pty_ary, count);

	return 0;
}

void print_str(char** pps, int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		printf("%s\n", pps[i]);
	}
}