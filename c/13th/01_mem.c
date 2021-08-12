#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

int main(void)
{
	int i;
	//局部变量未初始化，值是随机数
	int arr[MAX];

	for(i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar(10);
	//清空
	memset(arr, 0xFF, sizeof(arr));

	//拷贝函数
	memcpy();
	//移动
	memmove();

	for(i = 0; i < MAX; i++)
	{
		printf("%#x ", arr[i]);
	}
	putchar(10);
	return 0;
}
