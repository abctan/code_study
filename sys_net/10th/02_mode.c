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
#include <sys/socket.h>

int main(int argc, char *argv[])
{
	int i ;
	int a = 0x12345678;


	for (i = 0; i < 4; i++)
	{
		printf("%p : %x\n", ((char *)&a) + i, *(((char *)&a) + i));
	}

	if (*((char *)&a) == 0x78)
	{
		printf("little!\n");
	}
	else
	{
		printf("big!\n");
	}
	return 0;
}
