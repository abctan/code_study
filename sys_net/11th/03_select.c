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
#include <dirent.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int ret;
	int maxfd = 2;
	struct timeval it;
	fd_set fdr;
	int fd;
	char buf[128];

	mkfifo("./ken", 0666);

	fd = open("./ken", O_RDWR);
	
	it.tv_sec = 2;
	it.tv_usec = 0;

	
	while(1)
	{
		//清空集合
		FD_ZERO(&fdr);
		FD_SET(0, &fdr);
		FD_SET(fd, &fdr);
		maxfd = fd;

		ret = select(maxfd + 1, &fdr, NULL, NULL, NULL);
		/*ret = select(maxfd + 1, NULL, NULL, NULL, &it);*/
		if(ret == -1)
		{
			printf("select false!\n");
			return -1;
		}
		else if (ret == 0)
		{
			printf("time out!\n");
			return -1;
		}
		else
		{
			if (FD_ISSET(0, &fdr))
			{
				memset(buf, 0, sizeof(buf));
				read(0, buf, sizeof(buf));
				printf("stdin : %s\n", buf);
				/*write(fd, buf, strlen(buf) + 1);*/
			}
			else if (FD_ISSET(fd, &fdr))
			{
				memset(buf, 0, sizeof(buf));
				read(fd, buf, sizeof(buf));

				printf("mkfifo : %s\n", buf);
				write(0, buf, strlen(buf) + 1);
                /*
				 *for (i = 0; i < maxfd; i++)
				 *{
				 *    
				 *}
                 */
			}
			/*printf("ret : %d\n", ret);*/
		}
	}

	return 0;
}
