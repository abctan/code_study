#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t{
	//数据域 int char char * float structr 
	char name[64];
	//两个指针域
	struct node_t *next;//下一个节点地址
	struct node_t *prev; //上一个节点地址
};

//无头 无序 循环 双向
int main(void)
{
	char name[64];
	struct node_t *head = NULL;
	struct node_t *new = NULL;
	while(1)
	{
		printf("please input user name : ");
		fgets(name, sizeof(name), stdin);
		if (name[strlen(name) - 1] == '\n')
			name[strlen(name) - 1] = '\0';

		printf("name : %s\n",  name);	

		if (strcmp(name, "exit") == 0)
		{
			break;
		}
		//申请空间

		//初始化

		//插入到连链表中  尾插
		//先操作新来数据 ，在操作谁长就操作谁。

	}
	return 0;
}
