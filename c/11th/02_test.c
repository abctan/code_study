#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;

	printf("*p : %d\n", *p);
	p = (int *)malloc(4);

	*p = 123;

	printf("*p : %d\n", *p);
	free(p);
	printf("*p : %d\n", *p);

	return 0;
}
