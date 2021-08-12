#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <share.h>

#define INPUT 10
#define OUTPUT 3

int main(void)
{
	char buf[128];
	system("clear");

	while(1)
	{
		printf("\033[%d;10Hinput : \033[K\033[s", INPUT);	
		fgets(buf, sizeof(buf), stdin);
		buf[strlen(buf) - 1] = '\0';

		printf("\033[%d;10Hshow : %s\n\033[u", OUTPUT, buf);
		getchar();

	}
/*
 *    printf("\033[31;42mhello!\033[0m\n");
 *    printf("\033[33mw\033[34mo\033[36mr\033[35mld!\033[0m\n");
 *
 *    system("clear");
 *
 *    printf("\033[10;10Hhello!\n");
 *    printf("\033[2Aworld!\n");
 *    getchar();
 */
	return 0;
}
