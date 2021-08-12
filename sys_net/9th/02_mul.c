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
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>

#define MAX 10

int main(int argc, char *argv[])
{
	int i;
	pthread_t pthid;

	//进程号
	printf("pid : %d\n", getpid());

	//线程号
	pthid = pthread_self();
	printf("pthid : %lu\n", pthid);

	for (i = 0; i < MAX; i++)
	{
		if (fork() == 0)
		{
			printf("pid : %d ppid : %d pthid : %lu\n", getpid(), getppid(), pthread_self());
			exit(0);
		}
	}

	for (i = 0; i < MAX; i++)
	{
		wait(NULL);
	}
	return 0;
}
