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

#define NUM 10

//声明信号量锁描述符
extern semid;

void do_file(int fd)
{
	char buf[128];
	int count = 0;

	//加锁
	while(1)
	{
		lock(semid, 0);
		if (count == 1000)
		{
			unlock(semid, 0);
			break;
		}
		snprintf(buf, sizeof(buf), "pid : %d count = %d time = %d\n", getpid(), count++, time(NULL));
		
		write(fd, buf, strlen(buf));
		unlock(semid, 0);
	}

	close(fd);
	//解锁
	return ;
}


int operation_file(const char *path)
{
	int i;
	int fd;

	fd = creat(path, 0666);
	if (fd == -1)
	{
		return -1;
	}

	for (i = 0; i < NUM; i++)
	{
		if (fork() == 0)
		{
			/*printf("pid : %d ppid : %d\n", getpid(), getppid());*/
			do_file(fd);
			exit(0);
		}
	}

	for (i = 0; i < NUM; i++)
	{
		wait(NULL);
	}
	return 0;
}
