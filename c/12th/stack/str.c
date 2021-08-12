#include "stack.h"

void ls(void *data)
{
	printf("%c", *(char *)data);
}
int main(void)
{
	int i;
	STACK *handle = NULL;
	char buf[128];
	char ch = '\n';

	fgets(buf, sizeof(buf), stdin);
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	
	printf("buf : %s\n", buf);
	

	handle = stack_creat(sizeof(char), 1024);
	if (handle == NULL)
	{
		goto ERR1;
	}

	for (i = 0; i <= strlen(buf); i++)
	{
		if (buf[i] == '@')
		{
			stack_pop(handle);
		}
		else if (buf[i] == '#')
		{
			stack_push(&ch, handle);
		}
		else
		{
			stack_push(&buf[i], handle);
		}
	}

	stack_travel(handle, ls);
	printf("\n");

	stack_destroy(handle);
	return 0;
ERR1:
	return -1;
}
