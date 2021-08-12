#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GETLINES(string, buf) do{					\
				printf(string);						\
				fgets(buf, sizeof(buf), stdin);		\
				if (buf[strlen(buf) - 1] == '\n')	\
					buf[strlen(buf) - 1] = '\0';	\
			}while(0)


int main(void)
{
	char name[64];

	GETLINES("please input name : ", name);

	printf("name : %s\n", name);
	return 0;
}

