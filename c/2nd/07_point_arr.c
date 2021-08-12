#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i;
	//局部变量未初始化值是随机数
	int arr[5] = {1, 2, 3, 4, 5};
	int *p = NULL;

	
	// &arr arr
	p = arr;

	p = (int *)malloc(8);

	printf("sizeof(p) = %d\n", sizeof(p));

	printf("&arr : %p &arr + 1 : %p\n", &arr, &arr + 1);
	printf("arr : %p arr + 1 : %p\n", arr, arr + 1);
	for (i = 0; i < 5; i++)
	{
		/*printf("arr[%d] = %d\n", i, arr[i]);*/
		/*printf("arr[%d] = %d\n", i, *(p + i));*/
		printf("arr[%d] = %d\n", i, p[i]);
	}
	return 0;
}
