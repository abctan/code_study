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

int e = 1122;
int *q = NULL;//q => DS => heap

void *hello(void *data)
{
	int a;//运行时段空间地址
	int *p = NULL;//申请空间运行时段堆栈
	e = 3344;

	*q = 8899;

	printf("hello : *q = %d\n", *q);
	printf("hello : e = %d %p\n", e, &e);
	/*printf("hello : count = %d\n", count);*/
	printf("hello! pid : %d pthid : %lu\n" , getpid(), pthread_self());

	return NULL;
}
int main(int argc, char *argv[])
{
	int ret;
	pthread_t pthid = 0;
	int count = 1234;//no share  运行时段空间地址 
	int *p = NULL;// p => stack => heap

	q = (int *)malloc(sizeof(int));//heap
	if (q == NULL)
	{
		printf("malloc false!\n");
		return -1;
	}

	*q = 3344;

	printf("main : pid = %d pthid = %lu\n", getpid(), pthread_self());
	ret = pthread_create(&pthid, NULL, hello, NULL);

	sleep(1);
	printf("main : count = %d\n", count);
	printf("main : e = %d %p\n", e, &e);
	printf("ret : %d\n", ret);
	printf("pthid : %lu\n", pthid);
	printf("*q = %d\n", *q);
	return 0;
}
