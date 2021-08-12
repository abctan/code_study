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
	int *p = NULL;

	p = (int *)malloc(sizeof(int));
	if (p == NULL)
	{
		pthread_exit(NULL);
	}

	printf("hello : %p\n", p);

	*p = 4455;

	/*free(p);*/

	//表示线程退出
	pthread_exit(p);//yes heap 

}
int main(int argc, char *argv[])
{
	pthread_t pthid;
	int count = 1234;
	int **p = NULL;
	
	//1 创建线程
	ERRP(pthread_create(&pthid, NULL, hello, &count) != 0, pthread_create, goto ERR1);

	printf("&p : %p\n", &p);
	p = (int **)malloc(sizeof(int *));
	if (p == NULL)
	{
		printf("p malloc false!\n");
		return -1;
	}
	printf("p : %p\n", p);
/*
 *    *p = (int *)malloc(sizeof(int));
 *    if (*p == NULL)
 *    {
 *        printf("malloc *p false!\n");
 *        free(p);
 *        return -1;
 *    }
 *    printf("*p : %p\n", *p);
 *
 */
	// 线程等待
	ERRP(pthread_join(pthid, (void **)p) != 0, pthread_join, goto ERR2);

	//&p p *p 
	printf("p : %p *p : %p\n", p, *p);
	printf("*p : %d\n", **p);
	/*printf("main end! count = %d\n", count);*/

	free(*p);
	free(p);

	return 0;
ERR2:
	//线程销毁
	pthread_cancel(pthid);
ERR1:
	return -1;
}














