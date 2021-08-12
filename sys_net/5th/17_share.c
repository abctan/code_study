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

int main(int argc, char *argv[])
{
	
	if (vfork() == 0)
	{
		int count = 1122;//运行时段空间

		printf("child! count = %d\n", count);
		exit(0);
	}
	else
	{
		int count = 5566;//运行时段空间
		printf("parent! count = %d\n", count);
	}



	return 0;
}









