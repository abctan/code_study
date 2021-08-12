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
	int ret;
	time_t t;
	struct tm *tm = NULL;
	char buf[128];

	ret = time(&t);
	ERRP(ret == -1, time, goto ERR1);

	printf("ret : %d\n", ret);
	printf("t : %d\n", t);

	printf("time : %s\n", ctime(&t));

	/*tm = gmtime(&t);*/
	tm = localtime(&t);
	printf("year : %d\n", tm->tm_year + 1900);
	printf("month : %d\n", tm->tm_mon + 1);
	printf("day : %d\n", tm->tm_mday);
	printf("hours : %d\n", tm->tm_hour);
	printf("minutes : %d\n", tm->tm_min);
	printf("second : %d\n", tm->tm_sec);
	printf("week : %d\n", tm->tm_wday);


	memset(buf, 0, sizeof(buf));
	ret = strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M:%S %w %D", tm);
	printf("ret : %d\n", ret);

	printf("buf : %s\n", buf);
	return 0;
ERR1:
	return -1;
}
