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
	int fd1, fd2;

	/*fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);*/
	fd1 = creat(argv[1], 0666);

	write(fd1, "hello", 5);

	/*close(1);*/
	/*fd2 = dup(fd1);*/
	// 0 1 2
	fd2 = dup2(fd1, 1);

	/*fd2 = fd1;*/
	/*fd2 = creat(argv[1], 0666);*/

	write(1, "wrold", 5);

	printf("fd1 : %d fd2 : %d\n", fd1, fd2);
	return 0;
}
