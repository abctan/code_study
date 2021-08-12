#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//队列大小
#define MAX 10

//判断是否是满队
int is_full(int front, int end)
{
	return ((end + 1) % MAX == front) ? 1 : 0;
}

//判断是否是空队
int is_empty(int front, int end)
{
	return (front == end) ? 1 : 0;
}

//实现入队 end
void qe(int data, int *queue, int front, int *end)
{
	// 1 判断是否是满队
	if (is_full(front, *end))
		return ;
	// 2 保存数据
	queue[*end] = data;
	
	// 3 end偏移
	(*end)++;

	// 4 判断
	if (*end == MAX)
		*end = 0;

}

//实现出队
int de(int *queue, int *front, int end)
{
	int tmp;
	// 1 判断是否空队
	if (is_empty(*front, end))
		return -1;

	// 2 出数据
	tmp = queue[*front];

	// 3 偏移
	(*front)++;

	// 4 判断是否越界
	if (*front == MAX)
		*front = 0;

	return tmp;	
}

//求数据个数
int len(int front, int end)
{
	if (end > front)
		return end - front;
	return MAX - (front - end);
}

//遍历
void travel(int *queue, int front, int end)
{
	int i, j;
	
	for (i = 0, j = front; i < len(front, end); i++, j++)
	{
		if (j == MAX)
			j = 0;
		printf("%d ", queue[j]);
	}
	printf("\n");
}
int main(void)
{
	int i;
	int num;
	int queue[MAX];//定义一个队列
	int front = 0;//表示队头
	int end = 0;//表示队尾

	//接受数据
	for (i = 0; i < MAX; i++)
	{
		num = rand() % 100;
		printf("%d ", num);
		//入队
		qe(num, queue, front, &end);
	}
	printf("\n");

	travel(queue, front, end);
	//遍历

	printf("de : %d\n", de(queue, &front, end));
	printf("de : %d\n", de(queue, &front, end));
	qe(100, queue, front, &end);
	qe(101, queue, front, &end);
	qe(102, queue, front, &end);
	travel(queue, front, end);

	return 0;
}
