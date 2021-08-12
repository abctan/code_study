#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义栈的大小
#define MAX 10

//判断是否是满栈
int is_full(int top)
{
	if (top == MAX)
		return 1;
	return 0;	
}
//判断是否是空栈
int is_empty(int top)
{
	if (top == 0)
		return 1;
	return 0;	
}


//压栈函数
void push(int data, int *stack, int *top)
{
	//1 判断是否是满栈
	if (is_full(*top))
	{
		return ;
	}
	// 2 保存数据
	stack[*top] = data;
	
	//3 偏移栈顶指针
	(*top)++;

	return ;
}

//出栈
int pop(int *stack, int *top)
{
	// 1 判断是否是空栈
	if (is_empty(*top))
		return -1;
	
	// 2 栈顶指针偏移
	(*top)--;
	
	// 3 返回
	return stack[*top];
}


//遍历
void travel(int *stack)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", stack[i]);
	}
	putchar(10);
}

int main(void)
{
	int i;
	int num;
	//定义栈
	int stack[MAX];
	//栈顶指针
	int top = 0;

	for (i = 0; i < MAX + 2; i++)
	{
		num = rand() % 100;
		printf("%d ", num);
		
		//压栈
		push(num, stack, &top);
	}
	putchar(10);

	//遍历
	travel(stack);


	printf("pop : %d\n", pop(stack, &top));
	printf("pop : %d\n", pop(stack, &top));
	push(100, stack, &top);
	for (i = 0; i < MAX; i++)
		printf("pop : %d\n", pop(stack, &top));
	return 0;
}
