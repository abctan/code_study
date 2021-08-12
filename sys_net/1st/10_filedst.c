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

	while(1)
	{
		fd = open("./test", O_RDONLY);
		if (fd == -1)
		{
			break;
		}
		printf("fd : %d\n", fd);
	}
    /*
	 *close(2);
	 *fd = open("./test", O_RDONLY);
	 *printf("fd : %d\n", fd);
	 *fd = open("./test", O_RDONLY);
	 *printf("fd : %d\n", fd);
     */
	return 0;
}
