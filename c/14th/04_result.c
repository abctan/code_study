#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int num)
{
	if (num == 1)
	{
		return 1;
	}

	return add(num - 1) + num;
}

int main(void)
{
	printf("1 + 2 + 3 + ... + 100 = %d\n", add(100));

	return 0;
}
