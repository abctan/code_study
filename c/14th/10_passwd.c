#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int ret, i = 0;
	char ch;
	char buf[128] = {};
	system("stty -echo -icanon");

	//ecs => exit  backspace =1> 127
	printf("please input passwd : ");
	fflush(NULL);
	while(1)
	{
		printf("please input passwd : ");
		fflush(NULL);
		while(1)
		{
			ret = read(0, &ch, 1);
			if (ret == -1)
			{
				printf("read false!\n");
				return -1;
			}
			else if (ret == 1)
			{
				if (ch == 27)
				{
					break;
				}
				else if (ch == 127)
				{
					if (i == 0)
					{
						continue;
					}
					printf("\033[D");	
					putchar(' ');
					printf("\033[D");	
					fflush(NULL);
					i--;
				}
				else
				{
					putchar('*');
					fflush(NULL);
					buf[i++] = ch;
				}

			}
		}
		buf[i] = '\0';
		printf("passwd : %s\n", buf);
		i = 0;
	}
		system("stty echo icanon");

	return 0;
}
