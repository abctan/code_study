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
	int status;
	int ret;

	if (fork() == 0)
	{
		printf("child : %d\n", getpid());
		kill(getpid(), 6);
		abort();
		kill(getpid(), 64);
		_exit(123);
		exit(-1);
		exit(255 + 1);
	}

	/*ret = wait(&status);*/
	ret = waitpid(-1, &status, 0);
	ERRP(ret == -1, wait, goto ERR1);

	printf("WIFEXITED(status) : %d\n", WIFEXITED(status));
	printf("WEXITSTATUS(status) : %d\n", WEXITSTATUS(status));
	printf("===========\n");
	printf("WIFSIGNALED(status) : %d\n", WIFSIGNALED(status));
	printf("WTERMSIG(status) : %d\n", WTERMSIG(status));
    /*
	 *printf("status : %d %d\n", status, status / 256);
	 *printf("ret : %d\n", ret);
     */
	return 0;
ERR1:
	return -1;
}
