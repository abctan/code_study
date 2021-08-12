#ifndef __KEN_LLIST_H__
#define __KEN_LLIST_H__

//表示头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//函数指针
typedef void (llist_op_t)(void *);

//有头 无序 循环 双向链表
//链表节点信息结构体
struct node_t{
	void *data;				//数据域
	//指针域
	struct node_t *next;//下一个节点地址
	struct node_t *prev;//上一个节点地址
};
//抽象数据类型

typedef struct llist_t{
	struct node_t head; //表示所有数据
	int size;//数据类型
	int count; //数据个数
}LLIST;	


//函数生命
LLIST *llist_creat(int size);//初始化
int llist_insert_end(void *data, LLIST *handle);//尾插
void llist_travel_next(LLIST *handle, llist_op_t *op);//遍历
void llist_destroy(LLIST *handle);//销毁



#endif //LLIST_H
