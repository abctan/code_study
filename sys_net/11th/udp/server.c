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

//服务器

int main(int argc, char *argv[])
{
	int sd;
	int ret;
	char buf[128];
	struct sockaddr_in my_address, from;
	int len = sizeof(from);
	if (argc != 2)
	{
		printf("format : cmd + port\n");
		return -1;
	}

	//1 创建套接子
	sd = socket(AF_INET, SOCK_DGRAM, 0);//ctrl + p
	ERRP(sd == -1, socket, goto ERR1);

	// 2帮定端口
	my_address.sin_family = AF_INET;
	my_address.sin_port = htons(atoi(argv[1]));
	my_address.sin_addr.s_addr = INADDR_ANY;
	
	ret = bind(sd, (struct sockaddr *)&my_address, sizeof(my_address));
	ERRP(ret == -1, bind, goto ERR2);

	// 3 接受数据
	while(1)
	{
		ret = recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&from, &len);
		ERRP(ret == -1, recvfrom, goto ERR2);

		printf("ip : %s port : %d message : %s\n", inet_ntoa(from.sin_addr), ntohs(from.sin_port), buf);
	}
	//4 关闭
	close(sd);

	return 0;
ERR2:
	close(sd);
ERR1:
	return -1;
}
