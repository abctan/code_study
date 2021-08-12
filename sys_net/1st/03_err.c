#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <share.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <time.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>

//声明
extern errno;

int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	//"r" 'r'
	fp = fopen(argv[1], "r");
	if (NULL == fp)
	{
		/*printf("fopen false!\n");*/
		perror("fopen");
		printf("errno : %d\n", errno);
		printf("strerror : %s\n", strerror(errno));
		printf("strerror : %s\n", strerror(2));
		printf("strerror : %s\n", strerror(13));
		printf("strerror : %s\n", strerror(29));
		return -1;
	}

	printf("fopen success!\n");

	fclose(fp);
	return 0;
}
