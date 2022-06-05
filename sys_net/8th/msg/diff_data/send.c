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
#include "data.h"

int main(int argc, char *argv[])
{
	key_t key;
	int msgid;
	int ret;
	/*char buf[128] = {};*/
	struct cls_t cls = {1, "tom", 18, 'M'};
	struct tea_t tea = {3, 1, "laozhang"};

	//1 获取关键字
	
	ERRP((key = ftok(".", 123)) == -1, ftok, goto ERR1);
	printf("key : %#x\n", key);

	// 2 创建消息队列
	ERRP((msgid = msgget(key, IPC_CREAT)) == -1, msgget, goto ERR1);
	printf("msgid : %d\n", msgid);

	//3发送数据
	ERRP((ret = msgsnd(msgid, &cls, sizeof(cls), 0)) == -1, msgsnd, goto ERR1);

	ERRP((ret = msgsnd(msgid, &tea, sizeof(tea), 0)) == -1, msgsnd, goto ERR1);
	printf("ret : %d\n", ret);

	return 0;
ERR1:
	return -1;
}










