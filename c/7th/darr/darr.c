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

//删除，从后向前删除
void darr_del_end(void *key, darr_cmp_t *cmp, DARR *handle)
{

	int i;
	void *new = NULL;

	if (key == NULL)
	{
		printf("option key err!\n");
		return ;
	}

	/*for (i = handle->count; i >= 0; i--)*/
	for (i = handle->count - 1; i > 0; i--)
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
//指定位置删除
void darr_del_index(int index, DARR *handle)
{
	void *new = NULL;

	new = (void *)malloc(handle->size * (handle->count - 1));
	if (NULL == new)
	{
		return ;
	}

	memcpy(new, handle->data, handle->size * index);
	memcpy(new + handle->size * index, handle->data + handle->size * (index + 1), handle->size * (handle->count - index - 1));
	free(handle->data);
	handle->data = new;
	handle->count--;
	return ;
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
DARR *darr_find_all(void *key, darr_cmp_t *cmp, DARR *handle)
{
	int i;
	DARR *ind = NULL;


	ind = darr_creat(handle->size);
	if (ind == NULL)
	{
		printf("darr_creat false!\n");
		return NULL;
	}

	for (i = 0; i < handle->count; i++)
	{
		if (cmp(key, handle->data + i * handle->size) == 0)
		{
			darr_append(handle->data + i * handle->size, ind);
		}
	}
	return ind;
}
//按位置查找

void *darr_find_index(int index, DARR *handle)
{
	if (index < 0 || index >= handle->count)
	{
		return NULL;
	}


	return handle->data +  index * handle->size;
}

//排序
void darr_sort(DARR *handle, int flag, darr_cmp_t *cmp)
{
	int i, j;
	void *tmp = NULL;
	
	tmp = (void *)malloc(handle->size);
	if (tmp == NULL)
	{
		printf("malloc tmp !\n");
		return ;
	}
	//交换排序
	for (i = 0; i < handle->count; i++)
	{
		for (j = i + 1; j < handle->count; j++)
		{
			if (cmp(handle->data + i * handle->size, handle->data + j * handle->size) > 0)
			{
				//由小到大
				memcpy(tmp, handle->data + i * handle->size, handle->size);
				memcpy(handle->data + i * handle->size, handle->data + j * handle->size, handle->size);
				memcpy(handle->data + j * handle->size, tmp, handle->size);

			}
		}
	}
	free(tmp);
}

int darr_num(DARR *handle)
{
	return handle->count;
}

//存储
int darr_store(const char *path, DARR *handle)
{
	FILE *fp = NULL;
	int ret;
	//'w' "w"
	fp = fopen(path, "w");
	if (NULL == fp)
	{
		printf("fopen false!\n");
		return -1;
	}
	
	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	if (ret != 1)
	{
		printf("fwrite size false!\n");
		fclose(fp);
		return -1;
	}

	ret = fwrite(&handle->count, sizeof(handle->count), 1, fp);
	if (ret != 1)
	{
		printf("fwrite count false!\n");
		fclose(fp);
		return -1;
	}

	
	ret = fwrite(handle->data, handle->size, handle->count, fp);
	if (ret != handle->count)
	{
		printf("fwrite false!\n");
		fclose(fp);
		return -1;
	}

	//关闭
	fclose(fp);
	return 0;
}
//加载
DARR *darr_load(const char *path)
{
	FILE *fp = NULL;
	DARR *handle = NULL;
	int size, count;
	int ret;

	// 1 打开文件
	fp = fopen(path, "r");
	if (fp == NULL)
	{
		printf("fopen read false!\n");
		return NULL;
	}

	ret = fread(&size, sizeof(size), 1, fp);
	if (ret != 1)
	{
		printf("fread size false!\n");
		fclose(fp);
		return NULL;
	}
	ret = fread(&count, sizeof(count), 1, fp);
	if (ret != 1)
	{
		printf("fread count false!\n");
		fclose(fp);
		return NULL;
	}
	/*printf("size : %d count : %d\n", size, count);*/
	//2 初始化
	handle = darr_creat(size);
	if (handle == NULL)
	{
		printf("handle_create false!\n");
		fclose(fp);
		return NULL;
	}
	
	handle->count = count;
	//3 申请空间
	handle->data = (void *)malloc(size * count);
	if (handle->data == NULL)
	{
		printf("malloc data false!\n");
		free(handle);
		fclose(fp);
		return NULL;
	}
	ret = fread(handle->data, size, count, fp);
	if (ret != count)
	{
		printf("fread data false!\n");
		free(handle->data);
		free(handle);
		fclose(fp);
		return NULL;
	
	}
	return handle;
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
