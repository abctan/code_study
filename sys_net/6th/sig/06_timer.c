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

void hello(int sig)
{
	printf("hello : %d %d\n", sig, time(NULL));
}

int main(int argc, char *argv[])
{
	int ret;
	struct itimerval it;

	//2 捕捉定时器信号
	/*ERRP(signal(14, hello) == SIG_ERR, signal, goto ERR1);*/
	ERRP(signal(26, hello) == SIG_ERR, signal, goto ERR1);

	// 1 设定定时器
	//初始化闹钟时间
	//表示循环时间
	it.it_interval.tv_sec = 1;
	it.it_interval.tv_usec = 100000;

	//第一次执行时间
	it.it_value.tv_sec = 3;
	it.it_value.tv_usec = 1000;

	//设定定时器
	/*ret = setitimer(ITIMER_REAL, &it, NULL);*/
	ret = setitimer(ITIMER_VIRTUAL, &it, NULL);
	ERRP(ret == -1, setitimer, goto ERR1);

	/*getchar();//睡眠方式等待*/

	while(1)//轮询方式
		;

	return 0;
ERR1:
	return -1;
}
