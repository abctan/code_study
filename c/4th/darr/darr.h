//防止头文件重复包含
#ifndef __KEN_DARR_H__
#define __KEN_DARR_H__


//表示输入输出头文件
#include <stdio.h>
//str家族函数头文件 strcpy strcat strcmp strchr strlen memcpy ...
#include <string.h>
//申请内存空间头文件 malloc calloc realloc
#include <stdlib.h>

//函数指针
typedef void (darr_op_t)(void *);

//抽象数据类型
typedef struct darr_t{
	void *data;//表示数据
	int count;//表示数据个数
	int size;//表示数据类型
}DARR;


//初始化
DARR *darr_creat(int size);
//函数声明
//尾插
int darr_append(void *, DARR *handle);
//头插
int darr_appprev(void *, DARR *);
//指定位置插入
int darr_index_insert(void *data, int index, DARR *handle);


//遍历
void darr_travel(DARR *handle, darr_op_t *op);

//销毁
void darr_destroy(DARR *handle);

#endif //DARR_H




