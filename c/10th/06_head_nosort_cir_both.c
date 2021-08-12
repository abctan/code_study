#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//定义链表节点信息结构体
struct node_t{
	int data;	//数据
	struct node_t *next;//保存下一个节点地址
	struct node_t *prev;//保存上一个节点地址
};

//有头 无序 循环 双向链表
int main(void)
{
	int num;
	//定义链表头结点
	struct node_t head = {0, &head, &head};
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
		if (NULL == new)
		{
			return -1;
		}

		new->data = num;
		new->next = NULL;
		new->prev = NULL;

		#if 0
		// 尾插
		new->next = &head;
		new->prev = head.prev;
		head.prev->next = new;
		head.prev = new;
		#else
		new->next = head.next;
		new->prev = &head;
		head.next->prev = new;
		head.next = new;

		#endif
	}

	printf("next : ");
	for (tail = head.next; tail != &head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	putchar(10);

	printf("prev : ");
	for (tail = head.prev; tail != &head; tail = tail->prev)
	{
		printf("%d ", tail->data);
	}
	putchar(10);

	//销毁
	for (tail = head.next; tail != &head; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	return 0;
}
