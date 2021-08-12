#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERRP(con, func, ret) do{	\
			if (con)				\
			{						\
				printf(func);		\
				ret;				\
			}						\
	}while(0)

//定义链接节点信息
struct node_t{
	int data;
	struct node_t *next;
};

//有头 无序 不循环 单向
int main(void)
{
	int num;//临时变量，用于接受用户数据
	struct node_t head = {0, NULL};//头结点
	struct node_t *new = NULL;//新的节点，用户接受用户输入数据
	struct node_t *tail = NULL;//循环变量
	while(1)
	{
		printf("please input number : ");
		scanf("%d", &num);

		if (num == -1)
		{
			break;
		}

		//申请节点空间
		new = (struct node_t *)malloc(sizeof(struct node_t));
		ERRP(NULL == new, "malloc new false", goto ERR1);
		//空间初始化
		new->data = num;
		new->next = NULL;
		//
		/*head.next = new;*/
		//查找最后节点 next == NULL
		for (tail = &head; tail->next != NULL; tail = tail->next)
			;
		tail->next = new;	

	}

	//遍历
	for (tail = head.next; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");

	//销毁
	for (tail = head.next; tail != NULL; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	return 0;

ERR1:
	return -1;
}
