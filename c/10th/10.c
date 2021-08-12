#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//
struct node_t{
	char name[64];
	struct node_t *prev;
	struct node_t *next;
};

int main()
{
	char name[64];
	struct node_t *head=NULL;
	struct node_t *new=NULL;
	struct node_t *tail=NULL;
	while(1)
	{
		printf("please input usr name:");
		fgets(name,sizeof(name),stdin);

		if(name[strlen(name)-1] == '\n')
			name[strlen(name)-1] = '\0';

		printf("name:%s\n",name);

		if(strcmp(name,"exit")==0)
		{
			break;
		}
		//申请空间
		new=(struct node_t *)malloc(sizeof(struct node_t));
		if(new == NULL)
		{
			printf("malloc new flase！");
			return 0;
		}

		//初始化
		new->name = name;
		new->next = NULL;
		new->prev = NULL;

		//插入到链表中，尾插
		new->next = head;
		new->prev = head->prev;
		head->prev->next = new;
		head->prev = new;
	
		//先操作新来数据，在操作谁长谁操作

	}

	for(tail = head;tail->next != head;tail = tail->next)
	{
		printf("%s",tail->name);
	}
	printf("%s",tail->name);
	for(tail = head->next;tail != head;tail = tail->prev)
	{
		printf("%s",tail->name);
	}
	printf("%s",tail->name);

	for(tail = head->next;tail != head;tail = new)
		return ;    
}
