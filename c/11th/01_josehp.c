#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t{
	char *name;
	struct node_t *next;
	struct node_t *prev;
};


int main(void)
{
	int i;
	char name[64];
	struct node_t *head = NULL;
	struct node_t *new = NULL;
	struct node_t *tail = NULL;
	int m, n;
	int out = 0, count = 0;

	printf("please input m and n : ");
	scanf("%d%d", &m, &n);

	printf("m : %d n : %d\n", m, n);
	getchar();

	
	for (i = 0; i < m; i++)
	{
		printf("please input %d name : ", i + 1);
		fgets(name, sizeof(name), stdin);
		if (name[strlen(name) - 1] == '\n')
			name[strlen(name) - 1] = '\0';

		/*printf("name : %s\n", name);	*/

		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (NULL == new)
		{
			return -1;
		}

		new->name = (char *)malloc(strlen(name) + 1);
		if (new->name == NULL)
		{
			free(new);
			return -1;
		}
		strcpy(new->name, name);

		if (head == NULL)
		{
			new->next = new;
			new->prev = new;
			head = new;
		}
		else
		{
			new->next = head;
			new->prev = head->prev;
			head->prev->next = new;
			head->prev = new;
		}
	}


	for (tail = head; tail->next != head; tail = tail->next)
	{
		printf("%s ", tail->name);
	}
	printf("%s\n", tail->name);

	out = m;
	tail = head;
	while(out)
	{
		count++;//报数累加器
		new = tail->next;
		if (count == n)
		{
			printf("%s ", tail->name);
			tail->prev->next = tail->next;
			tail->next->prev = tail->prev;
			free(tail);
			out--;//退出累加器
			count = 0;
		}
		tail = new;
	}
	
	return 0;
}
