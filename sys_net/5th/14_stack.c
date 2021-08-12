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

int stack_size(void)
{
	char buf[1024] = {};
	static int count = 0;

	printf("count = %d\n", count++);
	stack_size();
}

int main(int argc, char *argv[])
{
	int ret;
	struct rlimit r;

	stack_size();

	ret = getrlimit(RLIMIT_NOFILE, &r);
	ERRP(ret == -1, getrlimit, goto ERR1);

	printf("r.rlim_cur = %d\n", r.rlim_cur);
	printf("r.rlim_max = %d\n", r.rlim_max);

	r.rlim_cur = 2000;

	ret = setrlimit(RLIMIT_NOFILE, &r);
	ERRP(ret == -1, setrlimit, goto ERR1);

	
	return 0;
ERR1:
	return -1;
}











