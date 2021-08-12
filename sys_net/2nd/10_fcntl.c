#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>

/*
 *#define O_ACCMODE      0003
 *#define O_RDONLY         00
 *#define O_WRONLY         01
 *#define O_RDWR           02
 *#define O_CREAT        0100 [> not fcntl <]
 *#define O_EXCL         0200 [> not fcntl <]
 *#define O_NOCTTY       0400 [> not fcntl <]
 *#define O_TRUNC       01000 [> not fcntl <]
 *#define O_APPEND      02000
 *#define O_NONBLOCK    04000
 *#define O_NDELAY    O_NONBLOCK
 *#define O_SYNC       010000
 *#define O_FSYNC      O_SYNC
 *#define O_ASYNC      020000
 */

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	int flag;

	/*fd = creat(argv[1], 0666);*/
	fd = open(argv[1], O_WRONLY);

	flag = fcntl(fd, F_GETFL);
	printf("flag : %o\n", flag);
	
	flag |= O_APPEND;
	fcntl(fd, F_SETFL, flag);
	flag = fcntl(fd, F_GETFL);

	printf("flag : %o\n", flag);

	write(fd, "hello", 5);

	
	return 0;
}
