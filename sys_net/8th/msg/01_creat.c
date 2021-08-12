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

int main(int argc, char *argv[])
{
	int msgid;

	//创建消息队列
	msgid = msgget(124, IPC_CREAT);
	if (msgid == -1)
	{
		printf("msgget false!\n");
		return -1;
	}

	printf("msgid : %d\n", msgid);
	return 0;
}












