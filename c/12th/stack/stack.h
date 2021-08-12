#ifndef __KEN_STACK_H__
#define __KEN_STACK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (stack_op_t)(void *);
//抽闲栈数据类型
typedef struct stack_t{
	void *stack;//数据
	int size;//类型
	int max;//大小
	int top;//栈顶指针
}STACK;


STACK *stack_creat(int size, int max);
int stack_is_full(STACK *handle);
int stack_is_empty(STACK *handle);
void stack_push(void *data, STACK *handle);
void *stack_pop(STACK *handle);
int stack_num(STACK *handle);
void stack_travel(STACK *handle, stack_op_t *op);
void stack_clean(STACK *handle);
void stack_destroy(STACK *handle);

#endif //STACK_H
