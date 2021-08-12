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

#define MIN 3000
#define MAX 6000
#define NUM 10
#define STEP (MAX - MIN) / NUM

int result = 0;

void *test(void *data)
{
	int i, j;
	/*printf("min : %d\n", *(int *)data);*/
	int min = *(int *)data;
	int max = min + STEP;

	*(int *)data = 0;

	for (i = min; i < max; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			(*(int *)data)++;
			result++;
		}
	}
	
	pthread_exit(data);
}

int main(int argc, char *argv[])
{
	int i;
	pthread_t pthid[NUM];
	int min[NUM];
	int *p = NULL;
	int count = 0;

	for (i = 0; i < NUM; i++)
	{
		min[i] = MIN + i * STEP;
		pthread_create(pthid + i, NULL, test, &min[i]);
	}

	for (i = 0; i < NUM; i++)
	{
		pthread_join(pthid[i], (void **)&p);
		count += *p;
	}

	printf("count : %d\n", count);
	printf("result : %d\n", result);
	return 0;
}
