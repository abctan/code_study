#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node_t{
	int data;
	struct node_t *next;
};

//无头 有序 不循环 单向
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
		new->next = NULL;

		if (head == NULL)
		{
			head = new;
		}
		else
		{
			if (new->data < head->data)
			{
				new->next = head;
				head = new;
			}
			else
			{
				for (tail = head; tail->next != NULL; tail = tail->next)
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

	for (tail = head; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	putchar(10);

	return 0;
}
