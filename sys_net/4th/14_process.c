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

int main(int argc, char *argv[])
{
	if (fork() == 0)
	{
		sleep(1);
		printf("child!\n");
		exit(0);
	}

	printf("parent!\n");
	wait(NULL);//确保子进程先运行
	return 0;
}
