#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//单向链表节点信息
struct node_t{
	int data;	//数据域 保存用户数据数据
	struct node_t *next;//指针域 保存下一个节点地址
};

//单向 无序 不循环  无头

int main(void)
{
	/*volatile int a = 10, d = 40, b = 2910, c = 3002;*/
	struct node_t head = {0, NULL};//头节点
	struct node_t volatile  a = {10,NULL},  d = {40, NULL}, b = {20, NULL}, c = {30, NULL};

	//链接 => 链表
	head.next = &a;
	a.next = &b;
	b.next = &c;

	printf("b : %d\n", a.next->data);
	printf("c : %d\n", a.next->next->data);
/*
 *    printf("a : %d : %p\n", a, &a);
 *    printf("b : %d : %p\n", b, &b);
 *    printf("c : %d : %p\n", c, &c);
 *    printf("d : %d : %p\n", d, &d);
 *
 *    printf("b : %d\n", *(&a - 1));
 *    printf("c : %d\n", *(&a - 2));
 */
	return 0;
}
