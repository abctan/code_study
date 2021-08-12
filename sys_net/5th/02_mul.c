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

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (fork() == 0)
		{
			sleep(1);
			printf("hello : %d %d\n", getpid(), getppid());
			/*exit(0);*/
			abort();
		}
	}

	for (i = 0; i < 10; i++)
	{
		wait(NULL);
	}	
	return 0;
}
