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

//客户端

int main(int argc, char *argv[])
{
	int sd;
	int ret;
	char buf[128];
	struct sockaddr_in to;
	int len = sizeof(to);
	
	if (argc != 3)
	{
		printf("format : cmd + port + ip!\n");
		return -1;
	}

	//1 创建套接子
	sd = socket(AF_INET, SOCK_DGRAM, 0);//ctrl + p
	ERRP(sd == -1, socket, goto ERR1);

	GETLINES("please input string : ", buf);
	// 2 发送数据
	to.sin_family = AF_INET;
	to.sin_port = htons(atoi(argv[1]));
	to.sin_addr.s_addr = inet_addr(argv[2]);

	ret = sendto(sd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&to, len);
	/*printf("hello! ret = %d\n", ret);*/
	ERRP(ret == -1, sendto, goto ERR2);


	//3 关闭
	close(sd);

	return 0;
ERR2:
	close(sd);
ERR1:
	return -1;
}
