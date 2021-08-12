#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

int cmp(const void *d1, const void *d2)
{
	return *(int *)d1 - *(int *)d2;
}

//初始化
void init_arr(int *arr, int size);

//遍历
void show_arr(int *arr, int size);

//交换排序
void swap(int *arr, int size);

//查找
int find(int *arr, int size, int key)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			return arr[i];
		}
	}

	return -1;
}
//实现二分查找法
int my_bsearch(int key, int *arr, int max)
{
	int l, h, m;

	l = 0;
	h = max - 1;

	while(l <= h)
	{
		m = (l + h) / 2;
		printf("m : %d\n", arr[m]);
		/*getchar();*/
		if (key == arr[m])
		{
			return arr[m];
		}
		else if (key > arr[m])
		{
			l = m + 1;
		}
		else if (key < arr[m])
		{
			h = m - 1;
		}
	}

	return -1;

}


int main(void)
{
	int *ind, key;
	/*srand(time(NULL));*/
	int arr[MAX];
	int num;

	//初始化
	init_arr(arr, sizeof(arr) / sizeof(arr[0]));
	//遍历
	show_arr(arr, sizeof(arr) / sizeof(arr[0]));

	swap(arr, MAX);
	show_arr(arr, sizeof(arr) / sizeof(arr[0]));

	printf("please input key : ");
	scanf("%d", &key);

	//ind = find(arr, MAX, key);
	/*ind = (int *)bsearch(&key, arr, MAX, sizeof(int), cmp);*/
	num = my_bsearch(key, arr, MAX);
	if (num == -1)
	{
		printf("no find!\n");
	}
	else
	{
		printf("ind : %d\n", num);
	}
    /*
	 *swap(arr, MAX);
	 *show_arr(arr, sizeof(arr) / sizeof(arr[0]));
     */

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

