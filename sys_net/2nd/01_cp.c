#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>

//cp format cmd option srcfilename destfilename
//open => fd => read write 
int main(int argc, char *argv[])
{
	int fdr, fdw;
	char buf[1024];
	int ret;

	ERRP((fdr = open(argv[1], O_RDONLY)) == -1, open read, goto ERR1);
	ERRP((fdw = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1, open write, goto ERR2);

	while( (ret = read(fdr, buf, sizeof(buf))) > 0)
	{
		write(fdw, buf, ret);
	}

	close(fdr);
	close(fdw);
	return 0;
ERR2:
	close(fdr);
ERR1:
	return -1;
}
