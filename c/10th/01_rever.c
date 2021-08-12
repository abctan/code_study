#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t{
	int data;
	struct node_t *next;
};

//有头 无序 不循环  单向
int main(void)
{
	int num;
	struct node_t head = {0, NULL};
	struct node_t *new = NULL, *tail = NULL;
	struct node_t *save = NULL, *prev = NULL;

	while(1)
	{
		printf("please input nuber : ");
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

		for (tail = &head; tail->next != NULL; tail = tail->next)
			;

		tail->next = new;	
	}

	for (tail = head.next; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	putchar(10);
	//=========================
	tail = head.next;
	while(tail != NULL)
	{
		save = tail->next;
		//printf("%d ", tail->data);

		tail->next = prev;
		prev = tail;

		tail = save;
	}
	head.next = prev;
	//========================


	for (tail = head.next; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	putchar(10);

	for (tail = head.next; tail != NULL; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	return 0;
}
