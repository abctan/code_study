#include <stdio.h>

int *test(void)
{
	int a = 10;

	return &a;
}

void test1(void)
{
	int b = 20;
}

int main(int argc char *argv[])
int main(void)
{
	int **q = NULL;
	int arr[2][3];

	&q q *q **q
	&arr arr arr[0] arr[0][0]


	int *p = NULL;
	int a[5] = {1,2,3,4,5};
	int b[5];

	/*b = {1,2,3,4,5};*/
	b = a;

	p = test();
	
	test1();

	printf("*p : %d\n", *p);
	return 0;
}
