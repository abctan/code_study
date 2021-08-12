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

	// 1 创建匿名管道
	pipe(fd);

	if (fork() == 0)
	{
		//child cat /etc/passwd
		close(fd[0]);
		// 1 => fd[1]
		dup2(fd[1], 1);
		execlp("cat", "cat", "/etc/passwd", NULL);
		exit(0);
	}

	wait(NULL);
	/*printf("parent!\n");*/
	close(fd[1]);
	dup2(fd[0], 0);
	execlp("grep", "grep", "root", NULL);
	//parent grep root
	return 0;
}
