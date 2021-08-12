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

int main(int argc, char *argv[], char *env[])
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	printf("============\n");
	i = 0;
	while(env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return 0;
}
