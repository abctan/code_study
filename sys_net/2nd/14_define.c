#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>

#define test(val) printf(#val" : %d\n", val)

int main(int argc, char *argv[])
{
	int a = 10;
	int b = 20;

	test(a);//printf("a : %d\n", a)
	test(b);//printf("b : %d\n", b);

	return 0;
}
