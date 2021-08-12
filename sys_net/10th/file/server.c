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

//服务器
int main(int argc, char *argv[])
{
	int fd;
	int ret;
	struct sockaddr_in src, from;
	int sd;
	int len;
	char buf[128] = {};

	// 1 创建网络套接子
	fd = socket(PF_INET, SOCK_STREAM, 0);
	ERRP(fd == -1, socket, goto ERR1);
	
	src.sin_family = AF_INET;
	src.sin_port = htons(PORT);
	src.sin_addr.s_addr = inet_addr("192.168.0.254");

	// 2 帮定端口
	ret = bind(fd, (struct sockaddr *)&src, sizeof(src));
	ERRP(ret == -1, bind, goto ERR2);

	// 3 监听客户连接
	ret = listen(fd, 30);
	ERRP(ret == -1, listen, goto ERR2);

	// 4 连接
	len = sizeof(from);
	sd = accept(fd, (struct sockaddr *)&from, &len);
	ERRP(sd == -1, accept, goto ERR2);

	while(1)
	{
		//5 接受数据
		memset(buf, 0, sizeof(buf));
		ret = read(sd, buf, sizeof(buf));
		/*ERRP(ret <= 0, read, goto ERR3);*/
		printf("%s", buf);
		
		/*printf("sd : %d ip : %s port : %d message : %s\n", sd, inet_ntoa(from.sin_addr), ntohs(from.sin_port), buf);*/

	}

	//关闭文件描述符
	close(sd);
	close(fd);
	return 0;
ERR3:
	close(sd);
ERR2:
	close(fd);
ERR1:
	return -1;
}
