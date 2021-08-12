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
	int ret;

	// aa
	printf("hostname : %s\n", getenv("HOSTNAME"));
	printf("hostname : %s\n", getenv("AA"));

	/*ret = setenv("AA", "aa.bb.com", 0);*/
	ret = putenv("HOSTNAME=aa.bb.cc");
	ERRP(ret == -1, setenv, goto ERR1);

	printf("hostname : %s\n", getenv("HOSTNAME"));
	printf("hostname : %s\n", getenv("AA"));

	unsetenv("HOSTNAME");
	printf("hostname : %s\n", getenv("HOSTNAME"));
	return 0;
ERR1:
	return -1;
}
