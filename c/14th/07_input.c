#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	
	//关闭回显
	system("stty -echo");
	//关闭缓冲区
	system("stty -icanon");

	while(1)
	{
		putchar(getchar());
		/*fflush(NULL);*/
	}

	system("stty echo");
	system("stty icanon");
	return 0;
}
