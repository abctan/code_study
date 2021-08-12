#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//递归
//直接递归：A => A
//间接递归：A => B => A


void hello(void)
{
	printf("hello world!\n");
	hello();
}

void test(int num)
{
	if (num == 0)
	{
		return ;
	}
	printf("push : %d\n", num);
	num -= 1;
	test(num);
	printf("pop : %d\n", num);
}
int main(void)
{
	test(5);	
	/*hello();*/
    /*
	 *while(1)
	 *{
	 *    printf("hello!\n");
	 *}
     */
	return 0;
}
