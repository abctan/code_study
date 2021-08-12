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
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
	char **q;
	// char *[]
	char *p[10];
	/*char [10][10] = {"hello", "world"}*/

	q = p;
	/*p[0] = "hello world";*/

	p[0] = (char *)malloc(128);

	strcpy(p[0], "hello world");
	p[0][0] = 'A';

	printf("*(p[0] + 0) : %c\n", p[0][0]);


	printf("p[0] : %s\n", p[0]);
	return 0;
}















