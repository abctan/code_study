#include "stack.h"

//初始化
STACK *stack_creat(int size, int max)
{
	STACK *handle = NULL;

	handle = (STACK *)malloc(sizeof(STACK));
	if (handle == NULL)
	{
		goto ERR1;
	}

	handle->stack = (void *)malloc(size * max);
	if (handle->stack == NULL)
	{
		goto ERR2;
	}
	
	memset(handle->stack, 0, size * max);//清空栈空间
	handle->size = size;
	handle->max = max;
	handle->top = 0;


	return handle;
ERR2:
	free(handle);
ERR1:
	return NULL;
}

//判断是否是满栈
int stack_is_full(STACK *handle)
{
	return handle->top == handle->max ? 1 : 0;
}

//判断是否是空栈
int stack_is_empty(STACK *handle)
{
	return handle->top == 0 ? 1 : 0;
}


//压栈
void stack_push(void *data, STACK *handle)
{
	//1 判断是否是满栈
	if (stack_is_full(handle))
		return ;

	// 2 保存数据到栈中
	memcpy(handle->stack + handle->top * handle->size, data, handle->size);

	//3 栈顶指针偏移
	handle->top++;
}

//弹栈
void *stack_pop(STACK *handle)
{
	if (stack_is_empty(handle))
		return NULL;

	handle->top--;

	return handle->stack + handle->top * handle->size;
}
//栈实际数据个数
int stack_num(STACK *handle)
{
	return handle->top;
}

//遍历
void stack_travel(STACK *handle, stack_op_t *op)
{
	int i;
	for (i = 0; i < handle->top; i++)
	{
		op(handle->stack + handle->size * i);
	}
}

//清空栈
void stack_clean(STACK *handle)
{
	memset(handle->stack, 0, handle->size * handle->max);
	handle->top = 0;
}

//销毁
void stack_destroy(STACK *handle)
{
	free(handle->stack);
	handle->stack = NULL;
	free(handle);
	handle = NULL;
}
