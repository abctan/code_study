#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node_t{
	int data;
	struct node_t *next;
};

//无头 无序 循环 单向
int main(void)
{
	int num;
	struct node_t *new = NULL, *tail = NULL;
	struct node_t *head = NULL;//无头

	while(1)
	{
		printf("please input nunber : ");
		scanf("%d", &num);

		if (num == -1)
		{
			break;
		}

		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (NULL == new)
		{
			return ;
		}

		new->data = num;

		if (head == NULL)
		{
			new->next = new;
			head = new;
		}
		else
		{
			for (tail = head; tail->next != head; tail = tail->next)
			{
				;
			}
			new->next = head;
			tail->next = new;	
		}

	}

	for (tail = head; tail->next != head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("%d\n", tail->data);

	return 0;
}
