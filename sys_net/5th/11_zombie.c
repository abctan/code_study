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

int main(int argc, char *argv[])
{
	if (fork() == 0)
	{
		printf("child! pid = %d ppid = %d\n", getpid(), getppid());
		exit(0);
	}

	while(1)
	{
		sleep(1);
		printf("parnet! pid = %d ppid = %d\n", getpid(), getppid());
	}
	return 0;
}
