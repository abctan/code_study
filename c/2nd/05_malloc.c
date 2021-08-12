#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;//循环变量
	int num;//临时变量，用于接受用户输入
	int *new = NULL;//存储数据空间
	int *prev = NULL;//保存旧的数据
	int count = 0;//累加器

	//int => char
	while(1)
	{
		//用户输入数据提示信息
		printf("please input number : ");
		scanf("%d", &num);
		
		//结束标记
		if (-1 == num)
		{
			break;
		}
		//申请空间 malloc
		/*new = (int *)realloc(new, sizeof(int) * (count + 1));*/
		new = (int *)malloc(sizeof(int) * (count + 1));
		if (NULL == new)
		{
			printf("malloc false!\n");
			return -1;
		}
		//内存拷贝函数 man memcpy
		
		//原来的数据拷贝新的空间地址中
		memcpy(new, prev, sizeof(int) * count);
		//释放空间
		free(prev);
		//保存用户数据数据给空间地址中
		*(new + count) = num;
		prev = new;

		//数据累加器
		count++;
	}

	//遍历
	for (i = 0; i < count; i++)
	{
		printf("%d ", new[i]);
	}
	putchar(10);

	//销毁
	free(new);
	return 0;
}
