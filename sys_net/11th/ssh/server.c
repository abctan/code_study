#define _XOPEN_SOURCE
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

int check_passwd(int fd)
{
	char buf[128];
	int ret;
	struct spwd *sp = NULL;
	char *p = NULL;

	sp = getspnam("root");
	if (sp == NULL)
	{
		return -1;
	}

	while(1)
	{
		ret = read(fd, buf, sizeof(buf));
		if (ret <= 0)
		{
			return -1;
		}
		printf("buf : %s\n", buf);
		p = crypt(buf, sp->sp_pwdp);
		if (p == NULL)
		{
			return -1;
		}

		if (strcmp(p, sp->sp_pwdp) == 0)
		{
			write(fd, "YES", 4);
		}
		else
		{
			write(fd, "NO", 3);
		}
	}

	return 0;
}

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
	/*src.sin_addr.s_addr = inet_addr("192.168.0.254");*/
	/*src.sin_addr.s_addr = INADDR_ANY; */
	src.sin_addr.s_addr = htonl(INADDR_ANY); 

	// 2 帮定端口
	ret = bind(fd, (struct sockaddr *)&src, sizeof(src));
	ERRP(ret == -1, bind, goto ERR2);

	// 3 监听客户连接
	ret = listen(fd, 30);
	ERRP(ret == -1, listen, goto ERR2);

	// 4 连接
	len = sizeof(from);
	while(1)
	{
		sd = accept(fd, (struct sockaddr *)&from, &len);
		ERRP(sd == -1, accept, goto ERR2);
		
		if (fork() == 0)
		{
			if (check_passwd(sd) == -1)
			{
				close(fd);
				exit(-1);
			}
			exit(0);
		}
		
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
