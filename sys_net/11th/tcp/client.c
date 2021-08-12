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
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define PORT 10086

//客户端
int main(int argc, char *argv[])
{
	int fd;
	int ret;
	struct sockaddr_in ser;//表示服务器结构体地址信息

	// 1 创建套接子
	fd = socket(PF_INET, SOCK_STREAM, 0);
	ERRP(fd == -1, socket, goto ERR1);

	printf("fd : %d\n", fd);

	ser.sin_family = AF_INET;
	ser.sin_port = htons(PORT);
	ser.sin_addr.s_addr = inet_addr(argv[1]);

	// 2 请求建立连接
	ret = connect(fd, (struct sockaddr *)&ser, sizeof(ser));
	ERRP(ret == -1, connect, goto ERR2);

	printf("connect success!\n");
	
	//3 发送数据
	ret = write(fd, argv[2], strlen(argv[2]) + 1);
	ERRP(ret <= 0, write, goto ERR2);

	close(fd);
	return 0;
ERR2:
	close(fd);
ERR1:
	return -1;
}










