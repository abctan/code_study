#include <stdio.h>



int main(void)
{
	int *p = NULL;
	int a = 123;
	int b = 1122;

	//p 

	p = &a;
	p = &b;
/*
 *    p = &a;
 *
 *    *p = 456;
 *
 *    a = 789;
 */

	printf("&a = %p a = %d\n", &a, a);
	printf("&p = %p p = %p *p = %d\n", &p, p, *p);
	return 0;
}
