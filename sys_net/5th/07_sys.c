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

int main(int argc, char *argv[], char **env)
{
	int ret;
	char *ar[] = {"ls", "-l", "-i", "-h", "-a", NULL};

	printf("main stat ...\n");
	/*ret = execl("ls", "ls", "-l", "-i", "-a", "-h", "/ken", NULL);*/
	/*ret = execlp("ls", "ls", "-l", "-i", "-a", "-h", "/ken", NULL);*/
	/*ret = execle("/bin/ls", "ls", "-l", "-i", "-a", "-h", "/ken", NULL, env);*/
	/*ret = execv("/bin/ls", ar);*/
	/*ret = execvp("ls", ar);*/
	ret = execve("/bin/ls", ar, env);
	printf("ret : %d\n", ret);
	/*system("ls -l -i -a -h /ken");//清屏*/
	/*system("hello");//清屏*/
	printf("main end ...\n");
	return 0;
}
