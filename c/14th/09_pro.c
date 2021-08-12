#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j;

	for (i = 0; i < 20; i++)
	{
		printf("\033[10;10H");
		for (j = 0; j <=i; j++)
		{
			printf("=");
		}	
		printf("> %*c %d%%", 20 - i, ' ', (i + 1) * 100 / 20);
		fflush(NULL);
		usleep(300000);
	}
	

	return 0;
}
