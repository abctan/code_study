#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//32为系统下，默认最大4个字节对齐，如果小于4个字节，则以成员类型最大的对齐
union a_t{
	char ch;
	int a;
	/*char *s;*/
	/*char ch1[5];*/
	/*double d;*/
	/*short s;*/
	/*char ch1;*/
	/*int a;*/
};

int main(void)
{
	union a_t a = {};
	a.ch = 'A';
	/*a.a = 66;*/
	printf("ch : %p a : %p\n", &a.ch, &a.a);
	printf("ch : %c a : %d\n", a.ch, a.a);
	printf("sizeof(union a_t) = %d\n", sizeof(union a_t));
	return 0;
}
