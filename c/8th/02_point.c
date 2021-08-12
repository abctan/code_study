#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;

	p = (int *)malloc(8);

	printf("sizeof(p) = %d\n", sizeof(p));
	return 0;
}
