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

void *world(void *data)
{
	printf("world : %d\n", *(int *)data);
	*(int *)data = 99999;

	printf("world : pid = %d pthid = %lu\n", getpid(), pthread_self());

	return NULL;
}

void *hello(void *data)
{
	int ret;
	pthread_t pthid;
	*(int *)data = 4567;
	printf("hello! pid : %d pthid : %lu\n" , getpid(), pthread_self());
	printf("hello : data = %d\n", *(int *)data);

	ret = pthread_create(&pthid, NULL, world, data);

	sleep(1);
	return NULL;
}
int main(int argc, char *argv[])
{
	int ret;
	pthread_t pthid = 0;
	int count = 1234;//no share  运行时段空间地址 

	printf("main : pid = %d pthid = %lu\n", getpid(), pthread_self());
	
	ret = pthread_create(&pthid, NULL, hello, &count);

	sleep(1);
	printf("main : count = %d\n", count);

	return 0;
}
