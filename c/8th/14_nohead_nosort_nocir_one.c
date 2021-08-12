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

//无头 无序 不循环 单向
int main(void)
{
	int num;//临时变量，用于接受用户数据
	struct node_t *head = NULL;//头结点
	struct node_t *new = NULL;//新的节点，用户接受用户输入数据
	struct node_t *tail = NULL;//循环变量

}
