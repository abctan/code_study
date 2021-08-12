#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10


//数组传参至少要传两个参数 数组传参就不具备数组特性，变成指针，
//第一个数组名
//第二个数组大小

//初始化
void init_arr(int *arr, int size);

//遍历
void show_arr(int *arr, int size);

void test(int *arr, int size)
{
	show_arr(arr, sizeof(arr) / sizeof(arr[0]));
}

int main(void)
{

	/*srand(time(NULL));*/
	int arr[MAX];
	
	//初始化
	init_arr(arr, sizeof(arr) / sizeof(arr[0]));
	//遍历
	show_arr(arr, sizeof(arr) / sizeof(arr[0]));


	if (cmp(key , arr[i]) > 0)
	{
		
	}
	if (key > arr[i])
	{
	
	}
	test(arr, MAX);
	return 0;
}

//函数实现
void init_arr(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void show_arr(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar(10);
}


