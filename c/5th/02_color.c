#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	while(1)
	{
		printf("\033[%d;%dH\033[31mh\033[32me\033[33ml\033[34mlo!\033[0m", rand() % 20, rand() % 89);
		fflush(NULL);
		usleep(10000);
	}
	return 0;
}
