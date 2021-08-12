#include <stdio.h>

void show(int arr[]);

int *test(void)
{
	int arr[5];

	return arr;
}

void init_arr(int arr[])
{
	int i;
	printf("init : sizeof(arr) = %d\n", sizeof(arr));
	printf("init : sizeof(arr[0]) = %d\n", sizeof(arr[0]));
	printf("init : sizeof(arr) / sizeof(arr[0]) = %d\n", sizeof(arr) / sizeof(arr[0]));
	printf("init : &arr : %p arr : %p\n", &arr, arr);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		arr[i] = rand() % 100;
	}
	/*show(arr);*/
}

void show(int *arr)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar(10);
}
int main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};

	/*arr = test();*/
	printf("main : sizeof(arr) = %d\n", sizeof(arr));
	printf("main : sizeof(arr[0]) = %d\n", sizeof(arr[0]));
	printf("main : sizeof(arr) / sizeof(arr[0]) = %d\n", sizeof(arr) / sizeof(arr[0]));

	printf("main : &arr : %p arr : %p\n", &arr, arr);
	show(arr);
	init_arr(arr);
	show(arr);

	return 0;
}
