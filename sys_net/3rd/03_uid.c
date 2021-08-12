#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>


char *get_name_uid(uid_t uid)
{
	char buf[128];
	FILE *fp = NULL;
	/*printf("uid : %d\n", uid);*/

	fp = fopen("/etc/passwd", "r");
	if (fp == NULL)
	{
		return NULL;
	}

	while(1)
	{
		if (fgets(buf, sizeof(buf), fp) == NULL)
		{
			return NULL;
		}
		if (atoi(strchr(strchr(buf, ':') + 1, ':') + 1) == uid)
		{
			printf("%s\n", buf);
			return NULL;
		}
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	printf("name : %s\n", get_name_uid(atoi(argv[1])));
	return 0;
}
