
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
	int ret;
	int fd;
	char buf[128] = {};

	ret = access(argv[1], F_OK);
	if (ret == -1)
	{
		//创建管道文件
		ret = mkfifo(argv[1], 0666);
		ERRP(ret == -1, mkfifo, goto ERR1);
	}
	printf("mkfifo success!\n");

	//打开管道文件
	fd = open(argv[1], O_RDWR);
	ERRP(fd == -1, open, goto ERR2);

	printf("fd : %d\n", fd);

	read(fd, buf, sizeof(buf));

	printf("buf : %s\n", buf);


	return 0;
ERR2:
	unlink(argv[1]);
ERR1:
	return -1;
}
