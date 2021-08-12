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

void hello(int sig)
{
	printf("hello!\n");
}

int main(int argc, char *argv[])
{
	
	printf("pid : %d\n", getpid());
	ERRP(signal(3, hello) == SIG_ERR, signal, goto ERR1);
	ERRP(signal(2, hello) == SIG_ERR, signal, goto ERR1);

	getchar();
	return 0;
ERR1:
	return -1;
}
