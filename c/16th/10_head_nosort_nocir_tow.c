#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node_t{
	int data;
	struct node_t *prev;
	struct node_t *next;
};

//有头 无序 循环  双向
int main()
{
	int num, i;
	struct node_t head = {0, &head, &head};
	struct node_t *new = NULL;
	struct node_t *tail = NULL;
	
	for(i = 0; i < 20 ;i++)
	{
		num = rand() % 100;

		new = (struct node_t *)malloc(sizeof(struct node_t));
		if(new == NULL)
		{
			printf("!!!\n");
			return ;
		}

		//初始化
		new->data = num;
		new->prev = NULL;
		new->next = NULL;

		for(tail = head.next; tail != &head; tail = tail->next)
		{
			;
		}
		new->next = &head;
		new->prev = head.prev;
		head.prev->next = new;
		head.prev = new;

	}

		for(tail = head.next; tail != &head; tail = tail->next)
		{
			printf("%d ",tail->data);
		}
		putchar(10);

}
