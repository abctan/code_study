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

int main(int argc, char *argv[])
{
	int i;

	for (i = 1; i <= 64; i++)
	{
		if(signal(i, SIG_DFL) == SIG_ERR)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
