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

int main(int argc, char *argv[])
{
	//接受参数
	char *ar[] = {"hello", "world", "test", NULL};
	char *ev[] = {"username=tom", "passwd=123123", "uid=5050", "gid=7070", NULL};

	execve("./test", ar, ev);
	return 0;
}
