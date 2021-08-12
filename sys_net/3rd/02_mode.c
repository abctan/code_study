#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>

/*
 *S_IFMT     0170000   bitmask for the file type bitfields
 *S_IFSOCK   0140000   socket				s => 12
 *S_IFLNK    0120000   symbolic link		l => 10
 *S_IFREG    0100000   regular file		- => 8
 *S_IFBLK    0060000   block device		b => 6
 *S_IFDIR    0040000   directory			d => 4
 *S_IFCHR    0020000   character device	c => 2
 *S_IFIFO    0010000   FIFO				p => 1
 */


int main(int argc, char *argv[])
{
	struct stat s;
	char *mode[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};//指针数组
	char type[] = " pc d b - l s";
	
	ERRP(stat(argv[1], &s) == -1, stat, goto ERR1);
	//type mode => s.st_mode


	printf("%c%s%s%s\n", type[(s.st_mode & S_IFMT) >>12], mode[(s.st_mode & S_IRWXU) >> 6], mode[(s.st_mode & S_IRWXG) >> 3], mode[(s.st_mode & S_IRWXO)]);

	return 0;
ERR1:
	return -1;
}
