#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEN 1

int main(void)
{

	//ifndef 判断宏是否存在，如果存在，则不执行 如果不存在，则执行
	//ifdef 相反
	#ifdef KEN
	printf("hello!\n");
	#endif
	return 0;
}
