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

typedef void (*sighandler_t)(int);

int main(int argc, char *argv[])
{
	sighandler_t p = NULL;

	printf("pid : %d\n", getpid());
	/*p = signal(SIGINT, SIG_DFL);*/
	p = signal(SIGINT, SIG_IGN);
	if (p == SIG_ERR)
	{
		printf("signal false!\n");
		return -1;
	}

	printf("p : %p\n", p);
	p = signal(SIGINT, SIG_DFL);
	if (p == SIG_ERR)
	{
		printf("signal false!\n");
		return -1;
	}

	printf("p : %p\n", p);
	p = signal(SIGINT, SIG_IGN);
	if (p == SIG_ERR)
	{
		printf("signal false!\n");
		return -1;
	}

	printf("p : %p\n", p);

	while(1)
		;
	return 0;
}
