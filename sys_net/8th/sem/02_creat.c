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

//全局锁变量描述符
int semid;
//加锁
int lock(int semid, int num)
{
	int ret;
	struct  sembuf op;

	op.sem_num = num;
	op.sem_op = -1;
	op.sem_flg = 0;
	ret = semop(semid, &op, 1);
	if (ret == -1)
	{
		return -1;
	}

	return 0;
}

//解锁
int unlock(int semid, int num)
{
	int ret;
	struct  sembuf op;

	op.sem_num = num;
	op.sem_op = 1;
	op.sem_flg = 0;
	ret = semop(semid, &op, 1);
	if (ret == -1)
	{
		return -1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	key_t key;
	int ret;
	int val = 1;

	//1 关键字
	key = ftok(".", 0x33);
	ERRP(key == -1, ftok, goto ERR1);

	//2 创建一个锁
	semid = semget(key, 1, IPC_CREAT);
	ERRP(semid == -1, semget, goto ERR1);
	printf("semid : %d\n", semid);

	//3 初始化这把锁
	ret = semctl(semid, 0, SETVAL, val);
	ERRP(ret == -1, semctl, goto ERR1);

	//4 设置加锁和解锁

	//5 调用文件
	operation_file(argv[1]);
	return 0;
ERR1:
	return -1;
}











