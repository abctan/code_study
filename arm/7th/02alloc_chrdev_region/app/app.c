#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int fd;
	char buf[128];

	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		perror("open");
		goto ERR1;
	}
	
	sleep(1);
	read(fd, buf, sizeof(buf));

	sleep(1);
	write(fd, buf, sizeof(buf));

	sleep(1);
	close(fd);
	return 0;
ERR1:
	return -1;
}


