#ifndef __KEN_LLIST_H__
#define __KEN_LLIST_H__

//表示头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define END		1
#define FIRST	2
#define INDEX	3

#define ERRP(con, func, ret) do{					\
				if (con)							\
				{									\
					printf("%s false!\n", func);	\
					ret;							\
				}									\
			}while(0)

#define GETLINES(string, buf) do{					\
				printf(string);						\
				fgets(buf, sizeof(buf), stdin);		\
				if (buf[strlen(buf) - 1] == '\n')	\
					buf[strlen(buf) - 1] = '\0';	\
			}while(0)

//函数指针
typedef void (llist_op_t)(void *);
typedef int (llist_cmp_t)(void *, void *);

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

void ls(void *);

//函数声明
LLIST *llist_creat(int size);//初始化

//插入实现
int llist_insert_end(void *data, LLIST *handle);//尾插
int llist_insert_first(void *data, LLIST *handle);//头插
int llist_insert_index(void *data, int index, LLIST *handle);//指定位置插入

//删除实现
int llist_del_first(void *key, llist_cmp_t *cmp, LLIST *handle);//从前到后删除
int llist_del_end(void *key, llist_cmp_t *cmp, LLIST *handle);//从后到前删除
int llist_del_index(int index, LLIST *handle);//指定位置删除
int llist_del_all(void *key, llist_cmp_t *cmp, LLIST *handle);//删除所有

//查找
void *llist_find_first(void *key, llist_cmp_t *cmp, LLIST *handle);//从前到后查找
void *llist_find_end(void *key, llist_cmp_t *cmp, LLIST *handle);//从后到前查找
void *llist_find_index(int index, LLIST *handle);//指定位置查找
LLIST *llist_find_all(void *key, llist_cmp_t *cmp, LLIST *handle);//查找所有

//求数据长度
int llist_num(LLIST *handle);

//排序
void llist_sort_asc(llist_cmp_t *cmp, LLIST *handle);//升序
void llist_sort_deasc(llist_cmp_t *cmp, LLIST *handle);//降序

//存储和加载
int llist_store(const char *path, LLIST *handle);//存储
LLIST *llist_load(const char *path);//加载

//遍历
void llist_travel_next(LLIST *handle, llist_op_t *op);//遍历
void llist_travel_prev(LLIST *handle, llist_op_t *op);//遍历

//销毁
void llist_destroy(LLIST *handle);//销毁



#endif //LLIST_H
