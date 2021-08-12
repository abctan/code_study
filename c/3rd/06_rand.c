#include <stdio.h>

int main(void)
{
	while(1)
	{
		printf("%d ", rand() % 50 + 50);//行缓冲行数
		fflush(NULL);//刷新输入和输出缓冲区
		sleep(1);
	}
	return 0;
}
