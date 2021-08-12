#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//表示不从外部接受用户输入
/*int main(void)*/
//第一个参数：表示接受参数个数
//第二个参数：表示指针数组 
int main(int argc, char *argv[])
{
	int i;
	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	//'1' => 1
	printf("s = %s\n", "123");
	printf("s = %d\n", atoi("123A456"));
	return 0;
}
