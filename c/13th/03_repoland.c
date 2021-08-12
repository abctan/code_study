#include "../12th/stack/stack.h"
#include <share.h>
//"1233-*"

//my_atoi  -48

void ls(void *data)
{
	printf("%d ", *(int *)data);
}
int main(void)
{
	int i, num;
	char buf[128];
	STACK *handle = NULL;
	int val1, val2;

	GETLINES("please input string : ", buf);
	printf("buf : %s\n", buf);

	handle = stack_creat(sizeof(int), 100);
	ERRP(handle == NULL, stack_create, goto ERR1);

	for (i = strlen(buf) - 1; i >= 0; i--)
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			num = buf[i] - 48;
			stack_push(&num, handle);
		}
	}

	stack_travel(handle, ls);
	printf("\n");

	for (i = 0; i < strlen(buf); i++)
	{
		if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' ||
				buf[i] == '/' || buf[i] == '%')
		{
			val1 = *(int *)stack_pop(handle);		
			val2 = *(int *)stack_pop(handle);		
			switch (buf[i])
			{
				case '+' :
					val1 += val2;
					break;
				case '-' :
					val1 -= val2;
					break;
				case '*' :
					val1 *= val2;
					break;
				case '/' :
					val1 /= val2;
					break;
				case '%' :
					val1 %= val2;
					break;
			}
			stack_push(&val1, handle);
		}
	}
	printf("result : %d\n", *(int *)stack_pop(handle));
	stack_destroy(handle);
	return 0;
ERR1:
	return -1;
}
