#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <time.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>


int **test(int a, int b)
{
	int i;
	int **p = NULL;

	//p *p **p

	p = (int **)malloc(sizeof(int *) * a);
	if (NULL == p)
	{
		return NULL;
	}

	for (i = 0; i < a; i++)
	{
		p[i] = (int *)malloc(sizeof(int) * b);
		if (p[i] == NULL)
		{
			while(i--)
			{
				free(p[i]);
			}
			free(p);
			return NULL;
		}
	}
	

	return p;
}

int main(int argc, char *argv[])
{
	int i, j;
	int arr[2][3];
	int **p = NULL;

	p = test(2, 3);

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			p[i][j] = rand() % 100;
		}
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("p[%d][%d] : %d\n", i, j, p[i][j]);
		}
	}
	return 0;
}
