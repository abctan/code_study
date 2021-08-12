#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//1970 1 1 => current
	while(1)
	{
		printf("time : %d\n", time(NULL));
		sleep(1);
	}	
	return 0;
}
