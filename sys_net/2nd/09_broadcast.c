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
	int ret;

	system("clear");

	fd = open(argv[1], O_RDONLY);

	while(1)
	{
		ret = read(fd, &ch, 1);
		if (ret != 1)
		{
			lseek(fd, 0, SEEK_SET);
			continue;
		}
		printf("\033[%dm%c\033[0m", rand() % 7 + 31, ch);
		usleep(100000);
		fflush(NULL);
	}
	return 0;
}
