#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	
	int fd;

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		return -1;
	}

	write(fd, "hello", 5);

	while(1)
	{
		;
	}

	close(fd);
	return 0;
}
