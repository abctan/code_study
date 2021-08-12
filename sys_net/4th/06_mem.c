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

int main(int argc, char *argv[])
{
	//=========================
	int ret;
	int count = 12345;//不共享

	//=======================
	ret = fork();
	if (ret == 0)
	{
		int tmp = 123;
		/*sleep(1);*/
		/*count = 1122;*/
		printf("child! count = %d %p tmp = %d\n", count, &count, tmp);
		/*printf("ptmp : %d\n", ptmp);*/
	}
	else
	{
		/*count = 3344;*/
		int ptmp = 456;//运行时段变量
		printf("parent : count = %d %p ptmp = %d %p\n", count, &count, ptmp, &ptmp);
	}
	/*printf("ptmp = %d\n", ptmp);*/
	return 0;
}
