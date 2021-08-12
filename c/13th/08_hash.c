#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

//定义hash节点信息
struct hash_t{
	int data;			//表示数据
	struct hash_t *next;//下一个节点地址
};


//实现HASH算法
int hash(int num)
{
	return num % MAX;
}
int main(void)
{
	struct hash_t head[MAX];//HASH头节点
	struct hash_t *new = NULL;//数据节点信息
	struct hash_t *tail = NULL;//循环变量
	int num, i;
	int index;
	int key, find;
	memset(head, 0, sizeof(head));

	srand(time(NULL));
	//创建hash表
	for (i = 0; i < MAX; i++)
	{
		num = rand() % 100;
		printf("%d ", num);

		new = (struct hash_t *)malloc(sizeof(struct hash_t));
		if (new == NULL)
		{
			return -1;
		}

		new->data = num;
		new->next = NULL;
		
		//调用hash算法函数
		index = hash(num);

		for (tail = &head[index]; tail->next != NULL; tail = tail->next)
			;
		tail->next = new;	

	}
	printf("\n");

	//hash遍历
	for (i = 0; i < MAX; i++)
	{
		printf("%d : ", i);
		for (tail = head[i].next; tail != NULL; tail = tail->next)
		{
			printf("%d ", tail->data);
		}
		printf("\n");
	}

	//hash查找
	printf("please input key : ");
	scanf("%d", &key);

	index = hash(key);
	
	for (tail = head[index].next; tail != NULL; tail = tail->next)
	{
		if (key == tail->data)
		{
			printf("find : %d\n", tail->data);
			goto loop;
		}
	}

	printf("no find!\n");
	
	loop:
	//hash销毁
	for (i = 0; i < MAX; i++)
	{
		for (tail = head[i].next; tail != NULL; tail = new)
		{
			new = tail->next;
			free(tail);
		}
	}

	return 0;
}
