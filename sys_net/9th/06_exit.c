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

void *hello(void *data)
{
	int a = 123;
	int *p = NULL;

	p = (int *)malloc(sizeof(int));
	if (p == NULL)
	{
		pthread_exit(NULL);
	}

	*p = 4455;

	*(int *)data = 456;
	printf("hello!\n");

    /*
	 *kill(getpid(), 9);
	 *return NULL;
	 *exit(0);
     */
	/*sleep(1);*/

	//表示线程退出
	pthread_exit(p);//yes heap 
	pthread_exit(&e);//yes DS
	pthread_exit(&a);//no run
	pthread_exit(data);//yes stack

}
int main(int argc, char *argv[])
{
	pthread_t pthid;
	int count = 1234;
	int *p = NULL;
	
	//1 创建线程
	ERRP(pthread_create(&pthid, NULL, hello, &count) != 0, pthread_create, goto ERR1);


	// 线程等待
	ERRP(pthread_join(pthid, (void **)&p) != 0, pthread_join, goto ERR2);

	printf("*p : %d\n", *p);
	/*printf("main end! count = %d\n", count);*/

	return 0;
ERR2:
	//线程销毁
	pthread_cancel(pthid);
ERR1:
	return -1;
}














