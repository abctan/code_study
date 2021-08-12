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

void hello(int sig)
{
	printf("sig : %d\n", sig);
}
int main(int argc, char *argv[])
{
	int fd[2];
	char buf[1024];
	int count = 0;

	//捕捉管道异常
	ERRP(signal(SIGPIPE, hello) == SIG_ERR, signal, goto ERR1);

	//1 创建匿名管道
	ERRP(pipe(fd) == -1, pipe, goto ERR1);

	//2 创建进程
	if (fork() == 0)
	{
		//child write => fd[1]
		sleep(1);
		/*close(fd[0]);*/
		write(fd[1], "hello", 5);
		exit(0);
	}

	//parent read => fd[0]
	close(fd[1]);
	close(fd[0]);
	wait(NULL);
	return 0;

ERR1:
	return -1;
}
