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

int e = 2233;

int main(int argc, char *argv[])
{
	int ret;
	int count = 1234;
	int *p = NULL;

	p = (int *)malloc(4);



	ret = vfork();
	/*ret = fork();*/
	if (ret == -1)
	{
		printf("vfork false!\n");
		return -1;
	}
	else if (ret == 0)
	{
		/*sleep(1);*/
		/*count = 4321;*/
		e = 1122;
		count = 4455;
		*p = 123;
		printf("child! pid = %d ppid = %d\n", getpid(), getppid());
		printf("child : e = %d\n", e);
		printf("child : count = %d\n", count);
		free(p);
		p = NULL;
		exit(0);
	}
	else
	{
		/*count = 1122;*/
		printf("parent! pid = %d ppid = %d\n", getpid(), getppid());
		printf("parent : e = %d\n", e);
		printf("parent : count = %d\n", count);
		printf("*p : %d\n", *p);
	}
	return 0;
}











