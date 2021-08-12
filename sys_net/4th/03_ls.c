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
	DIR *dir = NULL;
	struct dirent *dp = NULL;


	dir = opendir(argv[1]);
	ERRP(NULL == dir, opendir, goto ERR1);

	while(1)
	{
		dp = readdir(dir);
		ERRP(NULL == dp, readdir, goto ERR2);

		if (dp->d_name[0] == '.')
		{
			continue;
		}

		printf("%s\n", dp->d_name);
	}
	closedir(dir);

	return 0;
ERR2:
	closedir(dir);
ERR1:
	return -1;
}
