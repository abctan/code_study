#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <share.h>
#include <signal.h>

char ch;

void hello(int sig)
{
	if (ch == 'a' || ch == 'A')
	{
		printf("world!\n");
	}
	else
	printf("hello!\n");
}

int main(void)
{
	struct itimerval it;

	//2 接受定时器信号，执行相应操作
	ERRP(signal(SIGALRM, hello) == SIG_ERR, signal, goto ERR1);


	// 1 设定定时器
	//循环时间
	it.it_interval.tv_sec = 1;
	it.it_interval.tv_usec = 1000;
	//第一次执行时间
	it.it_value.tv_sec = 3;
	it.it_value.tv_usec = 1000;

	ERRP(setitimer(ITIMER_REAL, &it, NULL) == -1, setitier, goto ERR1);	

	while(1)
	{
		ch = getchar();
		printf("ch = %c\n", ch);
		getchar();

	}
	/*getchar();*/
	return 0;

ERR1:
	return -1;
}
