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

void *hello(void *data)
{
	printf("hello! pid : %d pthid : %lu\n" , getpid(), pthread_self());

	return NULL;
}
int main(int argc, char *argv[])
{
	int ret;
	pthread_t pthid = 0;

	printf("main : pid = %d pthid = %lu\n", getpid(), pthread_self());
	ret = pthread_create(&pthid, NULL, hello, NULL);

	/*printf("main : pid = %d pthid = %lu\n", getpid(), pthread_self());*/
	/*ret = pthread_create(&pthid, NULL, hello, NULL);*/
	sleep(1);
	
	printf("ret : %d\n", ret);
	printf("pthid : %lu\n", pthid);
	return 0;
}
