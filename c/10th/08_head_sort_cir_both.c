#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t{
	int data;
	struct node_t *next;
	struct node_t *prev;
};

int main(void)
{
	int num;	
	struct node_t head = {0, &head, &head};//循环双向链表
	struct node_t *new = NULL,  *tail = NULL;
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

		//
		for (tail = &head; tail->next != &head; tail = tail->next)
		{
			if (new->data < tail->next->data)
			{
				break;
			}
		}
		//insert data => tail end
		new->next = tail->next;
		new->prev = tail;
		tail->next->prev = new;
		tail->next = new;
	}

	for (tail = head.next; tail != &head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");
	return 0;
}
