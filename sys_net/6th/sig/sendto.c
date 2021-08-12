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
#include <signal.h>

int main(int argc, char *argv[])
{
    /*
	 *printf("hello!\n");
	 *kill(getpid(), 2);
	 *printf("world!\n");
     */
	if (fork() == 0)
	{
		printf("child!\n");
		sleep(1);
		kill(getppid(), 9);
		exit(0);
	}

	printf("parent!\n");
	return 0;
}
