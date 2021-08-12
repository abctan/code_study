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

void func(int sig)
{
	printf("sig : %d\n", sig);
	alarm(1);
}
int main(int argc, char *argv[])
{

	int count = 5;
	//捕捉闹钟信号
	ERRP(signal(SIGALRM, func) == SIG_ERR, signal, goto ERR1);

	//发送闹钟信息
	alarm(3);

	while(count--)
		pause();




    /*
	 *while(1)
	 *{
	 *    [>sleep(3);<]
	 *    alarm(3);
	 *}
     */

	/*getchar();*/

	return 0;
ERR1:
	return -1;
}





