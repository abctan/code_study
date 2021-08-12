#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int ret;
	char buf[128];

	ret = readlink(argv[1], buf, sizeof(buf));
	printf("ret : %d\n", ret);
	printf("buf : %s\n", buf);
	return 0;
}
