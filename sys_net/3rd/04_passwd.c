#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>
#include <pwd.h>

int main(int argc, char *argv[])
{
	struct passwd *pwd = NULL;

	while((pwd = getpwent()) != NULL)
	{
		printf("name : %10s uid : %3d shell : %s\n", pwd->pw_name, pwd->pw_uid, pwd->pw_shell);
	}
	printf("==========\n");
	setpwent();
	while((pwd = getpwent()) != NULL)
	{
		printf("name : %10s uid : %3d shell : %s\n", pwd->pw_name, pwd->pw_uid, pwd->pw_shell);
	}
	endpwent();
/*
 *    pwd = getpwuid(atoi(argv[1]));
 *    ERRP(NULL == pwd, getpwuid, goto ERR1);
 *
 *    printf("name : %s\n", pwd->pw_name);
 *    printf("shell : %s\n", pwd->pw_shell);
 */
	return 0;
ERR1:
	return -1;
}
