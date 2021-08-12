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

void test(void)
{
	printf("test!\n");
	_Exit(0);
	return ;
}

int main(int argc, char *argv[])
{

	test();

	printf("main!\n");
	
	exit(0);
	printf("main end!\n");
	return 0;
	/*test();*/
}
