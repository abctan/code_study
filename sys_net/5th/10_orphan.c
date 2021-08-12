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
		//child
		while(1)
		{
			printf("child : pid = %d ppid = %d\n", getpid(), getppid());
			sleep(1);
		}
		exit(0);
	}

	//parent
	sleep(3);
	return 0;
}
