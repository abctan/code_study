#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int a = 0x12345678;

	if (0x78 == *((char *)&a))
	{
		printf("little!\n");
	}
	else
	{
		printf("big!\n");
	}
	for (i = 0; i < 4; i++)
	{
		printf("%p : %#x\n", (char *)&a + i, *((char *)&a + i));
	}
	return 0;
}
