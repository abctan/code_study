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

int main(int argc, char *argv[])
{
	key_t key;
	int shmid;
	void *p =  NULL;
	char buf[128] = {};
	int ret;

	// 1 获取关键字
	key = ftok(".", 0x22);
	ERRP(key == -1, ftok, goto ERR1);

	printf("key : %#x\n", key);

	//2 创建共享内存
	shmid = shmget(key, 1024, IPC_CREAT);
	ERRP(shmid == -1, shmget, goto ERR1);

	printf("shmid : %d\n", shmid);

	//3 映射共享内存到进程中
	p = shmat(shmid, NULL, 0);
	ERRP(p == NULL, shmat, goto ERR1);
	
	printf("p : %p\n", p);

	// 4 解映射 是从进程中删除
	ret = shmdt(p);
	ERRP(ret == -1, shmdt, goto ERR1);

	printf("ret : %d\n", ret);

	//5 销毁共享内存 是从内核中删除
	ret = shmctl(shmid, IPC_RMID, NULL);
	ERRP(ret == -1, shmctl, goto ERR1);

	printf("ret : %d\n", ret);

	/*strcpy(p, "hello");*/

	#if 0
	//hello => p
	//4 写入数据到空间地址中
	strcpy(p, "hello");


	//5 读数据
	printf("p : %s\n", p);
	strcpy(buf, p);

	printf("buf : %s\n", buf);

	#endif
	return 0;
ERR1:
	return -1;
}
