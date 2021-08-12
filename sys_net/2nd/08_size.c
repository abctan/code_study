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
	int ret;

	/*fd = creat(argv[1], 0666);*/
	fd = open(argv[1], O_RDONLY);

	ret = lseek(fd, 0, SEEK_END);
	printf("size : %d\n", ret);

/*
 *    lseek(fd, 1024 * 1024 * 1024, SEEK_SET);
 *
 *    write(fd, "hello", 5);
 */

	return 0;
}
