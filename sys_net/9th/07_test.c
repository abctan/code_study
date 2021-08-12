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

void *test(void)
{
	int a = 123321;

	return &a;
}

void test1(void)
{
	int b = 456;
}


int main(int argc, char *argv[])
{
	int *p = NULL;

	p = test();
	test1();
	printf("*p : %d\n", *p);
	return 0;
}
