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

int write_file(int fd)
{
	char buf[128];
	int count = 0;
	int i;

	while(1)
	{
		if (count == 1000)
		{
			break;
		}
		snprintf(buf, sizeof(buf), "hello : pid = %d count = %d\n", getpid(), count++);
		for (i = 0; i < strlen(buf); i++)
		{
			write(fd, &buf[i], 1);
		}	
	}

	return 0;
}



int main(int argc, char *argv[])
{
	int fd;

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
	ERRP(fd == -1, open, goto ERR1);

	if (fork() == 0)
	{
		//child
		/*write(fd, "child", 5);*/
		ERRP(write_file(fd) != 0, write, goto ERR2);
		close(fd);
	}
	else
	{
		//parent
		/*sleep(1);*/
		/*write(fd, "parent", 6);*/
		sleep(1);
		ERRP(write_file(fd) != 0, write, goto ERR2);
		close(fd);
	}
	return 0;
ERR2:
	close(fd);
ERR1:
	return -1;
}
