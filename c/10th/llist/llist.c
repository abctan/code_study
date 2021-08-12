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


//遍历
void llist_travel_next(LLIST *handle, llist_op_t *op)
{
	struct node_t *tail = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
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
