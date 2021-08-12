#include "llist.h"

//初始化
LLIST *llist_creat(int size)
{
	LLIST *handle = NULL;

	handle = (LLIST *)malloc(sizeof(LLIST));
	if (NULL == handle)
	{
		return NULL;
	}
	handle->head.data = NULL;
	handle->head.next = &handle->head;
	handle->head.prev = &handle->head;
	handle->size = size;
	handle->count = 0;

	return handle;
}

//尾插
int llist_insert_end(void *data, LLIST *handle)
{
	struct node_t *new = NULL;

	if (data == NULL)
	{
		return -1;
	}
	//申请空间
	new = (struct node_t *)malloc(sizeof(struct node_t));
	if (NULL == new)
	{
		return -1;
	}

	new->data = (void *)malloc(handle->size);
	if (NULL == new->data)
	{
		free(new);
		return -1;
	}
	//初始化
	memcpy(new->data, data, handle->size);

	//添加链表
	new->next = &handle->head;
	new->prev = handle->head.prev;
	handle->head.prev->next = new;
	handle->head.prev = new;
	handle->count++;

	return 0;

}

//头插
int llist_insert_first(void *data, LLIST *handle)
{
	struct node_t *new = NULL;

	if (data == NULL)
	{
		return -1;
	}
	//申请空间
	new = (struct node_t *)malloc(sizeof(struct node_t));
	if (NULL == new)
	{
		return -1;
	}

	new->data = (void *)malloc(handle->size);
	if (NULL == new->data)
	{
		free(new);
		return -1;
	}
	//初始化
	memcpy(new->data, data, handle->size);

	new->next = handle->head.next;
	new->prev = &handle->head;
	handle->head.next->prev = new;
	handle->head.next = new;
	handle->count++;
	
	return 0;
}
//指定位置插入
int llist_insert_index(void *data, int index, LLIST *handle)
{
	int i;
	struct node_t *new = NULL;
	struct node_t *tail = &handle->head;

	ERRP(data == NULL, "llist_inset_index argvlist data ", goto ERR1);

	ERRP(index < 0 || index > handle->count, "llist_insert_index argvlist index", goto ERR1);
	
	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(new == NULL, "maloc new", goto ERR1);

	new->data = (void *)malloc(handle->size);
	ERRP(new->data == NULL, "malloc data", goto ERR2);

	memcpy(new->data, data, handle->size);

	for (i = 0; i < index; i++)
	{
		tail = tail->next;
	}

	new->next = tail->next;
	new->prev = tail;
	tail->next->prev = new;
	tail->next = new;
	handle->count++;

	return 0;
ERR2:
	free(new);
ERR1:
	return -1;
}


//删除 从后往前删除
int llist_del_end(void *key, llist_cmp_t *cmp, LLIST *handle)
{
	struct node_t *tail = NULL;


	for (tail = handle->head.prev; tail != &handle->head; tail = tail->prev)
	{
		if (cmp(key, tail->data) == 0)
		{
			tail->next->prev = tail->prev;
			tail->prev->next = tail->next;
			free(tail->data);
			free(tail);
			handle->count--;
			return 0;
		}
	}
	return -1;
}
//从前到后删除
int llist_del_first(void *key, llist_cmp_t *cmp, LLIST *handle)
{
	struct node_t *tail = NULL;


	for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
	{
		if (cmp(key, tail->data) == 0)
		{
			tail->next->prev = tail->prev;
			tail->prev->next = tail->next;
			free(tail->data);
			free(tail);
			handle->count--;
			return 0;
		}
	}
	return -1;
}
//指定位置删除删除
int llist_del_index(int index, LLIST *handle)
{
	struct node_t *tail = NULL;


	for (tail = handle->head.next; tail != &handle->head && --index; tail = tail->next)
		;
	
	tail->next->prev = tail->prev;
	tail->prev->next = tail->next;
	free(tail->data);
	free(tail);
	handle->count--;
	return 0;

	return -1;
}

//删除所有
int llist_del_all(void *key, llist_cmp_t *cmp, LLIST *handle)
{
	struct node_t *tail = NULL;
	struct node_t *save = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = save)
	{
		save = tail->next;
		if (cmp(key, tail->data) == 0)
		{
			tail->next->prev = tail->prev;
			tail->prev->next = tail->next;
			free(tail->data);
			free(tail);
			handle->count--;
			
		}
	}
	return 0;
}
//求数据长度
int llist_num(LLIST *handle)
{
	return handle->count;
}

//查找
void *llist_find_index(int index, LLIST *handle)
{
	struct node_t *tail = &handle->head;

	if (index <= 0)
	{
		return handle->head.next->data;
		return tail->next->data;
	}

	if (index >= handle->count)
	{
		/*return NULL;*/
		return handle->head.prev->data;
		return tail->prev->data;
	}

	while(index--)
	{
		tail = tail->next;
	}

	return tail->data;

}


//升序
void llist_sort_asc(llist_cmp_t *cmp, LLIST *handle)
{
	struct node_t *val1 = NULL, *val2 = NULL;
	struct node_t tmp;

	for (val1 = handle->head.next; val1 != &handle->head; val1 = val1->next)
	{
		for (val2 = val1->next; val2 != &handle->head; val2 = val2->next)
		{
			if (cmp(val1->data, val2->data) > 0)
			{
				tmp.data = val1->data;
				val1->data = val2->data;
				val2->data = tmp.data;
			}	
		}
	}
}

//存储和加载
int llist_store(const char *path, LLIST *handle)
{
	FILE *fp = NULL;
	struct node_t *tail = NULL;
	
	//打开文件
	fp = fopen(path, "w");
	ERRP(fp == NULL, "fopen file", goto ERR1);

	//保存数据类型 handle->size
	ERRP(fwrite(&handle->size, sizeof(handle->size), 1, fp) != 1, "fwrite size", goto ERR2);
	
	//保存数据个数 handle->count
	ERRP(fwrite(&handle->count, sizeof(handle->count), 1, fp) != 1, "fwrite count", goto ERR2);
	
	//保存数据 handle->head.next->data
	for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
	{
		ERRP(fwrite(tail->data, handle->size, 1, fp) != 1, "fwrite data", goto ERR2);
	}
	//关闭文件
	fclose(fp);
	return 0;
ERR2:
	fclose(fp);
ERR1:
	return -1;
}

//加载
LLIST *llist_load(const char *path)
{
	int i;
	LLIST *handle = NULL;
	FILE *fp = NULL;
	int size, count;
	void *tmp = NULL;

	fp = fopen(path, "r");
	ERRP(fp == NULL, "fopen fread", goto ERR1);

	//获取数据类型
	ERRP(fread(&size, sizeof(size), 1, fp) != 1, "fread size", goto ERR2);

	ERRP(fread(&count, sizeof(count), 1, fp) != 1, "fread count", goto ERR2);

	printf("size : %d count : %d\n", size, count);

	handle = llist_creat(size);
	ERRP(handle == NULL, "llist_creat", goto ERR2);

	tmp = (void *)malloc(size);
	ERRP(tmp == NULL, "malloc tmp", goto ERR3);

	for (i = 0; i < count; i++)
	{
		fread(tmp, size, 1, fp);
		/*ls(tmp);*/
		/*llist_insert_first(tmp, handle);*/
		llist_insert_end(tmp, handle);
	}

	fclose(fp);
	return handle;
ERR3:
	free(handle);
ERR2:
	fclose(fp);
ERR1:
	return NULL;
}

//遍历
void llist_travel_next(LLIST *handle, llist_op_t *op)
{
	struct node_t *tail = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
	{
		op(tail->data);
	}
}

void llist_travel_prev(LLIST *handle, llist_op_t *op)
{
	struct node_t *tail = NULL;

	for (tail = handle->head.prev; tail != &handle->head; tail = tail->prev)
	{
		op(tail->data);
	}
}

//销毁
void llist_destroy(LLIST *handle)
{
	struct node_t *tail = NULL, *save = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = save)
	{
		save = tail->next;
		free(tail->data);
		free(tail);
	}
	free(handle);
}
