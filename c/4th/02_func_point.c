#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef void (FUNC)(void);
void hello(void)
{
	printf("hello!\n");
}

void world(void)
{
	printf("world!\n");
}
void test(FUNC *p)
{
	p();
}
int main(void)
{

	//1 函数类型要保持一致
	//2 函数参数保持一致

	void (*p)(void);

	test(hello);
	test(world);
/*
 *    p = hello;
 *
 *    p = world;
 *
 *    p = add;
 *
 *    p();
 */
	/*hello();*/
	return 0;
}
