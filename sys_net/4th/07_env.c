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

int e = 1234;//DS

int main(int argc, char *argv[])
{
	int count = 1224;//stack
	int *p = NULL;

	p = (int *)malloc(sizeof(int));
	if (p == NULL)
	{
		printf("malloc false!\n");
		return -1;
	}
	
	*p = 123;
	//heap => auto memroy => malloc calloc realloc 
	if (fork() == 0)
	{
		/*sleep(1);*/
		e = 1122;
		printf("child! e = %d *p = %d\n", e, *p);
		free(p);
		p = NULL;
	}
	else
	{
		sleep(1);
		e = 3344;
		printf("parent! e = %d *p = %d\n", e, *p);
		free(p);
		/*free(p);*/
	}
	return 0;
}
