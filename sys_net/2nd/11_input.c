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
	char buf[128];
	int flag;

	flag = fcntl(0, F_GETFL);
	printf("input : %#o\n", flag);
	
	//表示取消阻塞
	flag |= O_NONBLOCK;
	fcntl(0, F_SETFL, flag);
	flag = fcntl(0, F_GETFL);
	printf("input : %#o\n", flag);

	sleep(3);
	read(0, buf, sizeof(buf));

	printf("buf : %s\n", buf);

	return 0;
}
