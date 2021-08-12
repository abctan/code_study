#define _GNU_SOURCE
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

int main(int argc, char *argv[])
{
	char *p = NULL;

	p = get_current_dir_name();
	ERRP(p == NULL, get_current_dir_name, goto ERR1);

	printf("pwd : %s\n", p);

	chdir("/tmp");

	ERRP(mkdir("./aa", 0777) == -1, mkdir, goto ERR1);

	printf("mkdir success!\n");
	free(p);
	return 0;
ERR1:
	return -1;
}
