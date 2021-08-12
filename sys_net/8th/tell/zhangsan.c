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

#define OUTPUT 3
#define INPUT 10
void clear_line(int num)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("\033[%d;1H\033[K", num + i);
	}
}
	
//有名管道
//zhangsan.c
//read   => ltoz => open => O_RDWR => fdr => child  => while (1) => exit
// write => ztol => open => O_RDWR => fdw => parent => while (1) => exit
int main(int argc, char *argv[])
{
	int fdr, fdw;
	char buf[128];

	//1 创建管道文件 判断管道文件是否存在
	//creat write file
	if (access("./ztol", F_OK) == -1)
	{
		ERRP(mkfifo("./ztol", 0666) == -1, mkfifo send file, goto ERR1);
	}

	//creat read filename
	if(access("./ltoz", F_OK) == -1)
	{
		ERRP(mkfifo("./ltoz", 0666) == -1, mkfifo recv file, goto ERR2);
	}

	//打开read write文件
	ERRP((fdr = open("./ltoz", O_RDWR)) == -1, open read, goto ERR3);
	
	ERRP((fdw = open("./ztol", O_RDWR)) == -1, open write, goto ERR4);


	system("clear");//清屏
	//创建父子进程
	if (fork() == 0)
	{
		//child => read
		/*printf("child!\n");*/
		printf("\033[%d;1HLISI : \n", OUTPUT);
		while(1)
		{
			read(fdr, buf, sizeof(buf));
			printf("\033[%d;1HLISI : \033[K%s\033[u", OUTPUT, buf);
			fflush(NULL);

			if (!strcmp(buf, "exit"))
			{
				break;
			}
		}
		exit(0);
	}

	//parent write
	/*printf("parent!\n");*/
	while(1)
	{
		printf("\033[%d;1HZHANGSAN : \033[K\033[s", INPUT);
		fgets(buf, sizeof(buf), stdin);
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		
		clear_line(INPUT);
        /*
		 *printf("\033[%d;1H\033[K", INPUT + 1);
		 *printf("\033[%d;1H\033[K", INPUT + 2);
         */
		write(fdw, buf, strlen(buf) + 1);

		if (!strcmp(buf, "exit"))
		{
			break;
		}
	}
	wait(NULL);
	close(fdr);
	close(fdw);
	unlink("./ltoz");
	unlink("./ztol");
	return 0;
ERR4:
	close(fdr);
ERR3:
	unlink("./ltoz");
ERR2:
	unlink("./ztol");
ERR1:
	return -1;
}
