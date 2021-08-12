#define _XOPEN_SOURCE
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

int main(int argc, char *argv[])
{
	char buf[128];
	char *p = NULL;
	struct spwd *pwd = NULL;

	pwd = getspnam(argv[1]);


	printf("passwd : %s\n", pwd->sp_pwdp);

	GETLINES("please input user passwd : ", buf);

	p = crypt(buf, pwd->sp_pwdp);

	if (strcmp(p, pwd->sp_pwdp) == 0)
	{
		printf("login ok!\n");
	}
	else
	{
		printf("login false!\n");
	}
	return 0;
}
