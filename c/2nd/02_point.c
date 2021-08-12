#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;

	printf("p : %p\n", p);
	//申请内存空间
	p = (int *)malloc(sizeof(int));
	/*p = (int *)calloc(2, sizeof(int));*/
	if (p == NULL)
	{
		printf("malloc false !\n");
		return -1;
	}
	printf("p : %p\n", p);

	printf("malloc success!\n");

	*p = 123;

	/*free(p);*/


	p = (int *)realloc(p, sizeof(int) * 2);

	*(p + 1) = 456;

	printf("*p = %d\n", *p);
	printf("*(p + 1) = %d\n", *(p + 1));

	//释放内存空间
	free(p);
	return 0;
}
