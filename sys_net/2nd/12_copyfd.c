#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>

int main(int argc, char *argv[])
{
	int fd;
	int fd1;

	/*close(1);*/
	fd = open(argv[1], O_RDWR);

	printf("fd : %d\n", fd);
	// 1 => fd => dup2
	close(1);
	fd1 = fcntl(fd, F_DUPFD, 1);

	printf("fd1 : %d\n", fd1);
	printf("hello!\n");
	write(fd1, "eorld", 5);
	return 0;
}
