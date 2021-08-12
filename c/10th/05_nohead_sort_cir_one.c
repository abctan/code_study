#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义节点信息结构体
struct node_t
{
	int data;
	struct node_t *next;
};

//无头 有序 循环 单向链表
int main(void)
{
	int num;
	struct node_t *head = NULL;
	struct node_t *new = NULL;
	struct node_t *tail = NULL;

	while(1)
	{
		//接受用户输入
		printf("please input number : ");
		scanf("%d", &num);

		//退出条件
		if (num == -1)
		{
			break;
		}

		//申请空间
		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (new == NULL)
		{
			return -1;
		}

		//init
		new->data = num;

		//添加新的节点带链表中 尾插
		if (head == NULL)
		{
			new->next = new;
			head = new;
		}
		else
		{
			//insert
			if (new->data < head->data)
			{
				new->next = head;
				for (tail = head; tail->next != head; tail = tail->next)
					;
				tail->next = new;	
				head = new;
			}
			else
			{
				for (tail = head; tail->next != head; tail = tail->next)
				{
					if (new->data < tail->next->data)
					{
						break;
					}
				}
				new->next = tail->next;
				tail->next = new;
			}
		}
	}

	//遍历
	for (tail = head; tail->next != head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("%d\n", tail->data);

	//销毁
	for (tail = head; tail->next != head; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	free(tail);

	//销毁
	return 0;
}
