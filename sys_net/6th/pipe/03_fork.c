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

int main(int argc, char *argv[])
{
	int fd[2];
	char buf[128];

	//1 创建匿名管道
	ERRP(pipe(fd) == -1, pipe, goto ERR1);

	//2 创建进程
	if (fork() == 0)
	{
		//child write => fd[1]
		close(fd[0]);
		while(1)
		{
			printf("please input string : ");
			fgets(buf, sizeof(buf), stdin);
			if (buf[strlen(buf) - 1] == '\n')
				buf[strlen(buf) - 1] = '\0';

			write(fd[1], buf, strlen(buf));

			if (strcmp(buf, "exit") == 0)
			{
				break;
			}
		}
		exit(0);
	}

	//parent read => fd[0]
	close(fd[1]);
	while(1)
	{
		memset(buf, 0, sizeof(buf));//清空buf
		read(fd[0], buf, sizeof(buf));
		if (strcmp(buf, "exit") == 0)
		{
			break;
		}
		printf("buf : %s\n", buf);
	}
	wait(NULL);
	return 0;

ERR1:
	return -1;
}
