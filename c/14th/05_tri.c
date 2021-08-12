#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pristatar(int num)
{
	int i;

	for (i = 0; i < num; i++)
	{
		printf("* ");
	}
	printf("\n");
}

void priline(int num)
{
	if (num == 0)
	{
		return ;
	}
	priline(num - 1);
	pristatar(num);
}

int main(void)
{
	//
	priline(5);

	return 0;
}
