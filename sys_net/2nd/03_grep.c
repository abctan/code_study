#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>

//format : grep => argv[0] key => argv[1] filename => argv[2]
//fileIO => fgets => "r" => buf => strstr => printf
int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char buf[128];
	char tmp[128];
	int ret;
	char *p = NULL;
	char *s = NULL;
	int count = 0;

	fp = fopen(argv[2], "r");
	ERRP(NULL == fp, fopen, goto ERR1);

	while((fgets(buf, sizeof(buf), fp)) != NULL)
	{
		count++;
		p = buf;
		while ((s = strstr(p, argv[1])) != NULL)
		{
			memset(tmp, 0, sizeof(tmp));

			strncpy(tmp, p, s - p);
			printf("%s", tmp);
			printf("\033[31m%s\033[0m", argv[1]);
			p = s + strlen(argv[1]);
		/*printf("%d : %s", count, buf);*/
		}
		if (p != buf)
		{
			printf("%s", p);
		}	
	}

	fclose(fp);
	return 0;
ERR1:
	return -1;
}
