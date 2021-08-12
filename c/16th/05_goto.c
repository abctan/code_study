#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	
	//深层退出
	while(1)
	{
		while(1)
		{
			printf("hello!\n");
			goto loop;
			/*break;*/
		}
		/*break;*/
	}
	loop:


	//循环
    /*
	 *loop:
	 *printf("world!\n");
	 *goto loop;
     */
	

	//容错
	return 0;
}
