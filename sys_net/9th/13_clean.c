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

void aa(void *data)
{
	printf("aaaa!\n");
}
void bb(void *data)
{
	printf("bbbb!\n");
}
void cc(void *data)
{
	printf("cccc!\n");
}

int main(int argc, char *argv[])
{
	printf("main start ...\n");
	//注册
	pthread_cleanup_push(aa, NULL);
	pthread_cleanup_push(bb, NULL);
	pthread_cleanup_push(cc, NULL);


	//执行
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(3);
	pthread_cleanup_pop(4);
	/*pthread_cleanup_pop(1);*/

	printf("main end ...\n");
	return 0;
}
