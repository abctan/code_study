//表示输入输出头文件
#include <stdio.h>
//str家族函数头文件 strcpy strcat strcmp strchr strlen memcpy ...
#include <string.h>
//申请内存空间头文件 malloc calloc realloc
#include <stdlib.h>


#define MAX 10


//函数声明
//实现插入    新的数据   旧的数据   数据长度    数据类型（大小）
void *insert(void *cls, void *prev, int *count, int size);

int main(void)
{
	int i;
	int count = 0;
	int num;
	int *new = NULL;

	for (i = 0; i < MAX; i++)
	{
		num = rand() % 100;
		printf("%d ", num);
		//插入函数实现 函数调用
		new = insert(&num, new, &count, sizeof(int));

	}
	printf("\n");

	//遍历
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", new[i]);
	}
	printf("\n");
		
	//销毁	
	free(new);
	return 0;
}


//函数实现
void *insert(void *data, void *prev, int *count, int size)
{
	void *new = NULL;

	//申请空间
	new = (void *)malloc(size * (*count + 1));
	if (new == NULL)
	{
		return NULL;
	}

	#if 0
	//数据保存到空间中
	memcpy(new, prev, size * (*count));
	free(prev);
	memcpy(new + (*count) * size, data, size);
	#endif

	//拷贝新的数据给new，且保存在第一个位置
	memcpy(new, data, size);
	//拷贝旧的数据给new ,但是new向后偏移一个数据大小
	memcpy(new + size, prev, size * (*count));
	free(prev);

	(*count)++;
	return new;
}
