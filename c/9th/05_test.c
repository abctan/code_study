#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;

	int a[5] = {1,2,3,4,5};
	p = &a[0];//yes
	p = a;//yes
	
	p = &a;//no

	//1 条件用于成立
	while(1)
	

	return 0;
}
