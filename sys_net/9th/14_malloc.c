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

void free_mem(void *data)
{
	free(data);
}

int main(int argc, char *argv[])
{
	int *p = NULL;

	p = (int *)malloc(sizeof(int));

	pthread_cleanup_push(free_mem, p);

	pthread_cleanup_pop(1);

	free(p);

	return 0;
}
