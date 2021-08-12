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
#include <pthread.h>
#include <signal.h>
int main(int argc, char *argv[])
{
	printf("hello!\n");
	kill(getpid(), 10);
	/*kill(getpid(), SIGKILL);*/
	/*kill(getpid(), 9);*/
	/*abort();*/
	/*pthread_exit(NULL);*/
	printf("world!\n");
	return 0;
}
