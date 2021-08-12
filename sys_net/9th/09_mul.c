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

//3000 ~ 6000 

void *do_work(void *data)
{
	printf("pthid : %lu pid : %d\n", pthread_self(), getpid());

	/*return NULL;*/
	/*exit(0);*/

	pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
	int ret;
	int i;
	pthread_t pthid[MAX];

	for (i = 0; i < MAX; i++)
	{
		ret = pthread_create(&pthid[i], NULL, do_work, NULL);
		if (ret != 0)
		{
			return -1;
		}
	}


	for (i = 0; i < MAX; i++)
	{
		pthread_join(pthid[i], NULL);
	}

	for (i = 0; i < MAX; i++)
	{
		printf("pthid[%d] = %lu\n", i, pthid[i]);
	}
	return 0;
}
