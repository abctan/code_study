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
	char ch;

	fd = open(argv[1], O_RDONLY);

	/*lseek(fd, 10, SEEK_SET);*/
	lseek(fd, -2, SEEK_END);

	read(fd, &ch, 1);

	printf("ch : %c\n", ch);

/*
 *    system("clear");
 *    lseek(1, 10, SEEK_SET);
 *
 *    write(1, "hello", 5);
 *    getchar();
 */

	return 0;
}
