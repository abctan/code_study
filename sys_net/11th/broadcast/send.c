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

#define PORT 10086

//发送广播
int main(int argc, char *argv[])
{
	int fd, sd;
	char ch;
	int ret;
	struct sockaddr_in to;
	int val = 1;
	
	//打开文件
	fd = open("/etc/passwd", O_RDONLY);
	ERRP(fd == -1, open, goto ERR1);

	//创建网络套接子
	sd = socket(AF_INET, SOCK_DGRAM, 0);
	ERRP(sd == -1, socket, goto ERR2);

	//设置套接子为广播模式
	ret = setsockopt(sd, SOL_SOCKET, SO_BROADCAST, &val, sizeof(val));
	ERRP(ret == -1, setsockopt, goto ERR2);


	//广播地址初始化
	to.sin_family = AF_INET;
	to.sin_port = htons(PORT);
	to.sin_addr.s_addr = inet_addr("192.168.0.255");//表示广播地址

	while(1)
	{
		ret = read(fd, &ch, 1);
		if (ret == 0)
		{
			lseek(fd, 0, SEEK_SET);
			continue;
		}

		/*putchar(ch);*/

		ret = sendto(sd, &ch, 1, 0, (struct sockaddr *)&to, sizeof(to));
		ERRP(ret != 1, sendto, goto ERR2);

		fflush(NULL);
		usleep(10000);
	}


	close(sd);
	close(fd);
	return 0;
ERR2:
	close(fd);
ERR1:
	return -1;
}
