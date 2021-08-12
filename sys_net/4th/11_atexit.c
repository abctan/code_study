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

void hello(void)
{
	printf("hello!\n");
}

void world(void)
{
	printf("world!\n");
}

void test(void)
{
	printf("test!\n");
}

int main(int argc, char *argv[])
{
	printf("main start!\n");
	
	//=> 6
	atexit(hello);
	atexit(world);
	atexit(test);

	printf("main end!\n");
	//=> 10
	return 0;
}
