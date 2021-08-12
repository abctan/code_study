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

	/*fd = open(argv[1], O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);*/
	fd = open(argv[1], O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
	{
		return -1;
	}
	return 0;
}
