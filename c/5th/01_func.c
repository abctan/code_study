#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//函数
void test(void)
{
	printf("hello!\n");
}

//指针函数
void *test1(void)
{
	printf("test1!\n");
	return NULL;
}

int main(void)
{
	//定义函数指针
	void (*p)(void);

	//函数指针
	void *(*q)(void);


	p = test;

	p();
	q = test1;

	q();

	/*test();*/

	return 0;
}
