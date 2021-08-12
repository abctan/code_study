#include "darr.h"

//初始化
DARR *darr_creat(int size)
{
	DARR *handle = NULL;

	handle = (DARR *)malloc(sizeof(DARR));
	if (handle == NULL)
	{
		printf("malloc handle false!\n");
		return NULL;
	}

	handle->data = NULL;
	handle->size = size;
	handle->count = 0;

	return handle;
}

//头插函数实现
int darr_append(void *data, DARR *handle)
{
	void *new = NULL;

	//申请空间
	new = (void *)malloc(handle->size * (handle->count + 1));
	if (new == NULL)
	{
		return -1;
	}

	//数据保存到空间中
	memcpy(new, handle->data, handle->size * handle->count);
	free(handle->data);
	memcpy(new + handle->count * handle->size, data, handle->size);
	handle->data = new;

	handle->count++;

	return 0;
}

//遍历
void darr_travel(DARR *handle, darr_op_t *op)
{
	int i;

	for (i = 0; i < handle->count; i++)
	{
		op(handle->data + i * handle->size);
	}
}

//销毁
void darr_destroy(DARR *handle)
{
	free(handle->data);
	free(handle);
	handle = NULL;
}
