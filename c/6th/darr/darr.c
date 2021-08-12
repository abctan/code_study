#include "darr.h"

//初始化  //ctrl + o
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

//头插
int darr_appprev(void *data, DARR *handle)
{
	void *new = NULL;


	if (data == NULL)
	{
		printf("option err!\n");
		return -1;
	}

	new = (void *)malloc(handle->size * (handle->count + 1));
	if (NULL == new)
	{
		printf("malloc new false!\n");
		return -1;
	}

	//
	memcpy(new, data, handle->size);
	memcpy(new + handle->size, handle->data, handle->count * handle->size);
	free(handle->data);
	handle->data = new;
	handle->count++;

	return 0;

}

//指定位置插入
int darr_index_insert(void *data, int index, DARR *handle)
{
	void *new = NULL;


	if (data == NULL)
	{
		printf("data false!\n");
		return -1;
	}

	if (index > handle->count || index < 0)
	{
		printf("index false!\n");
		return -1;
	}

	new = (void *)malloc(handle->size * (handle->count + 1));
	if (NULL == new)
	{
		printf("malloc new false!\n");
		return -1;
	}


	memcpy(new, handle->data, handle->size * index);
	memcpy(new + handle->size * index, data, handle->size);
	memcpy(new + handle->size * (index + 1), handle->data + handle->size * index, handle->size * (handle->count - index));
	free(handle->data);
	handle->data = new;
	handle->count++;
	
	return 0;
}

//=========================================
//按关键字删除
void darr_del_first(void *key, darr_cmp_t *cmp, DARR *handle)
{
	int i;
	void *new = NULL;

	if (key == NULL)
	{
		printf("option key err!\n");
		return ;
	}

	for (i = 0; i < handle->count; i++)
	{
		if (cmp(key, handle->data + handle->size * i) == 0)
		{
			new = (void *)malloc(handle->size * (handle->count - 1));
			if (new == NULL)
			{
				printf("darr_del_first : malloc new false!\n");
				return ;
			}

			memcpy(new, handle->data, handle->size * i);
			memcpy(new + handle->size * i, handle->data + handle->size * (i + 1), handle->size * (handle->count - i - 1));
			free(handle->data);
			handle->data = new;
			handle->count--;
			return ;
		}
	}
}


//删除所有
void darr_del_all(void *key, darr_cmp_t *cmp, DARR *handle)
{
	int i;
	void *new = NULL;

	if (key == NULL)
	{
		printf("option key err!\n");
		return ;
	}

	for (i = 0; i < handle->count; i++)
	{
		if (cmp(key, handle->data + handle->size * i) == 0)
		{
			/*darr_del_first(key, cmp, handle);*/
			new = (void *)malloc(handle->size * (handle->count - 1));
			if (new == NULL)
			{
				printf("darr_del_all : malloc new false!\n");
				return ;
			}

			memcpy(new, handle->data, handle->size * i);
			memcpy(new + handle->size * i, handle->data + handle->size * (i + 1), handle->size * (handle->count - i - 1));
			free(handle->data);
			handle->data = new;
			handle->count--;
			i--;
		}
	}
	
}

//=============================
//按关键字查找
void *darr_find_first(void *key, darr_cmp_t *cmp, DARR *handle)
{
	int i;

	for (i = 0; i < handle->count; i++)
	{
		if (cmp(key, handle->data + i * handle->size) == 0)
		{
			return handle->data + i * handle->size;
		}
	}

	return NULL;
}

//从后往前查找
//查找所有
//按位置查找

int darr_num(DARR *handle)
{
	return handle->count;
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
