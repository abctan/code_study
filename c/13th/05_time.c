#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//12M
#define MAX 2500000

int cmp(const void *d1, const void *d2)
{
	return *(int *)d1 - *(int *)d2;
}

//数组传参至少要传两个参数 数组传参就不具备数组特性，变成指针，
//第一个数组名
//第二个数组大小

//初始化
void init_arr(int *arr, int size);

//遍历
void show_arr(int *arr, int size);

//交换排序
void swap(int *arr, int size);

//冒泡排序
void bubble(int *arr, int size);

//选择排序
void sel(int *arr, int size);

//插入排序
void insert(int *arr, int size);

int main(int argc, char **argv)
{

	/*srand(time(NULL));*/
	int arr[MAX];
	
	//初始化
	init_arr(arr, sizeof(arr) / sizeof(arr[0]));

	switch (atoi(argv[1]))
	{
		case 1:
			/*printf("swap\n");*/
			swap(arr, MAX);
			break;
		case 2:
			/*printf("bubble!\n");*/
			bubble(arr, MAX);
			break;
		case 3:
			/*printf("select!\n");*/
			sel(arr, MAX);
			break;
		case 4:
			/*printf("insert\n");*/
			insert(arr, MAX);
			break;
		case 5:
			qsort(arr, MAX, sizeof(int), cmp);
			break;
		default :
			printf("option err!\n");
			break;

	}
	//遍历
	/*show_arr(arr, sizeof(arr) / sizeof(arr[0]));*/

	/*swap(arr, MAX);*/
	/*bubble(arr, MAX);*/
	/*sel(arr, MAX);*/
    /*
	 *insert(arr, MAX);
	 *show_arr(arr, sizeof(arr) / sizeof(arr[0]));
     */

	/*show_arr(arr, sizeof(arr) / sizeof(arr[0]));*/
	return 0;
}

//函数实现
void init_arr(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % MAX;
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


//交换排序
void swap(int *arr, int size)
{
	int tmp;
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

//冒泡排序
void bubble(int *arr, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
			}
		}
	}
}


//选择排序
void sel(int *arr, int size)
{
	int i, j, save, tmp;
	
	for (i = 0; i < size; i++)
	{
		save = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[save] > arr[j])
			{
				save = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[save];
		arr[save] = tmp;
	}
}

//插入排序
void insert(int *arr, int size)
{
	int i, j, save;

	for (i = 1; i < size; i++)
	{
		save = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (save < arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = save;
	}



}


