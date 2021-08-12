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
	printf("hello! pid : %d ppid : %d\n", getpid(), getppid());
	getchar();
	return 0;
}
