#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * test()
{

	p = (int *)malloc(4);
	return p;
}
int main(void)
{
	int *p = NULL;

	p = test();

	*p = 123;


	return 0;
}
