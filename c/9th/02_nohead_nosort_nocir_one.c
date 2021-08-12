#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义节点信息结构体
struct node_t
{
	int data;
	struct node_t *next;
};

//无头 无序 不循环 单向链表
int main(void)
{
	int num;
	struct node_t *head = NULL;
	struct node_t *new = NULL;
	struct node_t *tail = NULL;

	while(1)
	{
		printf("please input number : ");
		scanf("%d", &num);

		if (num == -1)
		{
			break;
		}

		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (new == NULL)
		{
			return -1;
		}

		//init
		new->data = num;
		new->next = NULL;

		if (head == NULL)
		{
			head = new;
		}
		else
		{
			//insert
			for (tail = head; tail->next != NULL; tail = tail->next)
				;
			tail->next = new;
		}
	}

	for (tail = head; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");


	//
	return 0;
}
