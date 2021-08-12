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
	int ret;

	ret = access(argv[1], F_OK | );
	ERRP(ret == -1, access, goto ERR1);

	printf("ok!\n");
	return 0;
ERR1:
	return -1;
}
