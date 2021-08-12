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
	key_t key;
	int msgid;
	int ret;
	char buf[128] = {};

	//1 获取关键字
	
	ERRP((key = ftok(".", 123)) == -1, ftok, goto ERR1);
	printf("key : %#x\n", key);

	// 2 创建消息队列
	ERRP((msgid = msgget(key, IPC_CREAT)) == -1, msgget, goto ERR1);
	printf("msgid : %d\n", msgid);

	//4接受数据
	ret = msgrcv(msgid, buf, sizeof(buf), 0, IPC_NOWAIT);
	ERRP(ret == -1, msgrcv, goto ERR1);

	printf("buf : %s\n", buf);
	return 0;
ERR1:
	return -1;
}











