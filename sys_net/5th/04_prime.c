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

#define MIN 3000
#define MAX 6000
#define NUM 10
#define STEP ((MAX) - (MIN)) / (NUM)
//只能被1 和 本身整除的数就是素数或者质数
int count_prime(int min, int max)
{
	int i;
	int j;
	int count = 0;

	printf("pid : %d min : %d max : %d\n", getpid(), min, max);
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
			/*printf("%d ", i);*/
			count++;
		}
	}

	return count;
}

int main(int argc, char *argv[])
{
	int count = 0;
	int i;
	int status;

	for (i = 0; i < NUM; i++)
	{
		if (fork() == 0)
		{
			exit(count_prime(MIN + STEP * i, MIN + STEP * (i + 1)));
			/*printf("hello : %d\n", getpid());*/
			/*exit(0);*/
		}
	}

	for (i = 0;  i < NUM; i++)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			count += WEXITSTATUS(status);
		}
	}
	printf("count : %d\n", count);
    /*
	 *count = count_prime(3000, 6000);
	 *printf("count : %d\n", count);
     */
	return 0;
}
