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

int  binary(int num)
{
	int i, count = 0;

	for (i = 31; i >= 0; i--)
	{
		if ((i + 1)% 4 == 0)
		{
			putchar(' ');
		}
		if (((num >> i) & 1) == 1)
		{
			putchar('1');
			count++;
		}
		else
		{
			putchar('0');
		}
	}
	putchar(10);

	return count;
}

int main(int argc, char *argv[])
{
	int num;

	printf("please input number : ");
	scanf("%d", &num);

	printf("num : %d\n", num);

	if (binary(num) % 2)
	{
		printf("odd!\n");
	}
	else
	{
		printf("even!\n");
	}

	return 0;
}
