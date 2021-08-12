#include "stack.h"

#define MAX 5

void ls(void *data)
{
	printf("%d ", *(int *)data);
}

int main(void)
{
	int num;
	int i;
	STACK *handle = NULL;

	handle = stack_creat(sizeof(int), MAX);
	if (handle == NULL)
	{
		goto ERR1;
	}

	for (i = 0; i < MAX; i++)
	{
		num = rand() % 100;
		printf("%d ", num);
		stack_push(&num, handle);
	}
	putchar(10);

	//遍历
	stack_travel(handle, ls);
	putchar(10);
	printf("pop : %d\n", *(int *)stack_pop(handle));
	printf("pop : %d\n", *(int *)stack_pop(handle));
	printf("pop : %d\n", *(int *)stack_pop(handle));
	printf("pop : %d\n", *(int *)stack_pop(handle));
	printf("pop : %d\n", *(int *)stack_pop(handle));
	printf("pop : %d\n", *(int *)stack_pop(handle));
	
	return 0;
ERR1:
	return -1;
}
