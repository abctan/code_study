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
	int t = time(NULL);

	printf("time : %d\n", t);
	printf("second : %d\n", t % 60);
	printf("minuts : %d\n", t / 60 % 60);
	printf("hours : %d\n", t / 60 / 60 % 24 + 8);
	return 0;
}
