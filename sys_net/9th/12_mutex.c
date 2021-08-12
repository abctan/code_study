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

#define NUM 10

//全局锁变量
/*pthread_mutex_t mutex;*/
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void *test(void *data)
{
	char buf[128];
	int fd = *(int *)data;
	int count = 1000;
	/*printf("fd : %d\n", fd);*/

	//加锁
	pthread_mutex_lock(&mutex);

	while(count--)
	{
        /*
		 *if ()
		 *{
		 *    pthread_exit(NULL);
		 *}
         */
		snprintf(buf, sizeof(buf), "pthid : %lu count : %d\n", pthread_self(), count);
		write(fd, buf, strlen(buf));
	}
	/*close(fd);*/

	//解锁
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int i;
	pthread_t pthid[NUM];
	int fd;

	//初始化锁
	/*pthread_mutex_init(&mutex, NULL);*/


	fd = creat(argv[1], 0666);
	if (fd == -1)
	{
		printf("open false!\n");
		return -1;
	}

	for (i = 0; i < NUM; i++)
	{
		pthread_create(pthid + i, NULL, test, &fd);
	}

	for (i = 0; i < NUM; i++)
	{
		pthread_join(pthid[i], NULL);
	}

	close(fd);
	
	//销毁
	/*pthread_mutex_destroy(&mutex);*/

	return 0;
}
