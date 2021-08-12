
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//定义节点信息
struct node_t{
	int data;              //数据域
	struct node_t *next;  //指针域
};

int main(void)
{
	int num;
	int i;
	struct node_t *head = NULL;
	struct node_t *new = NULL;
	struct node_t *tail = NULL;

	for(i = 0; i < 20; i++)
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
		new->next = NULL;

		//判断头节点是不是为空
		if(head == NULL)
		{
			head = new;
			printf("hello!\n");
		}
		else
		{
			for(tail = head; tail->next != NULL; tail = tail->next)
			;
			tail->next = new;
			printf("World!\n");
		}

	}
		//遍历
		for(tail = head; tail != NULL; tail = tail->next)
		{
			printf("%d ", tail->data);
		}
		putchar(10);

		//销毁
		for(tail = head->next; tail != NULL;tail = new)
		{
			new = tail->next;
			free(tail);
		}

}




