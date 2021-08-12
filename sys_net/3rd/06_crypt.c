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

int main(int argc, char *argv[])
{
	char key1[128], key2[128];
	char *c = NULL;

	system("stty -echo -icanon");

	GETLINES("Password: ", key1);
	putchar(10);
	GETLINES("Retype password:", key2);
	putchar(10);
	if (strcmp(key1, key2))
	{
		printf("Sorry, passwords do not match.\n");
		system("stty echo icanon");
		return -1;
	}
	/*printf("Password: ");*/
	c = crypt(key1, "$1$Kc81kkrT$");
	ERRP(NULL == c, crypt, goto ERR1);
	printf("passwd : %s\n", c);
	system("stty echo icanon");
	return 0;
ERR1:
	return -1;
}
