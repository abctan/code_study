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

//服务端口号
#define PORT 10086

//接受方
int main(int argc, char *argv[])
{
	int sd;
	struct sockaddr_in myaddr, from;
	char ch;
	int len = sizeof(from);
	int ret;
	int val = 1;

	//创建
	sd = socket(AF_INET, SOCK_DGRAM, 0);
	ERRP(sd == -1, socket, goto ERR1);

	//设置端口重用
	ret = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	ERRP(ret == -1, setsockopt, goto ERR2);

	//帮定
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(PORT);
	myaddr.sin_addr.s_addr = INADDR_ANY;
	
	ERRP(bind(sd, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1, bind, goto ERR2);

	while(1)
	{
		ret = recvfrom(sd, &ch, 1, 0, (struct sockaddr *)&from, &len);
		ERRP(ret != 1, recvfrom, goto ERR2);

		putchar(ch);
		fflush(NULL);
	}

	close(sd);
	return 0;
ERR2:
	close(sd);
ERR1:
	return -1;
}
