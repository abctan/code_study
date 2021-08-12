#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>

int main(int argc, char *argv[])
{
	int ret;
	struct stat s;
	mode_t m;

	ret = lstat(argv[1], &s);
	if (ret == -1)
	{
		printf("stat false!\n");
		goto ERR1;
	}
	m = s.st_mode;

	#if 0
/*
 *    S_ISREG(m)  is it a regular file?
 *    S_ISDIR(m)  directory?
 *    S_ISCHR(m)  character device?
 *    S_ISBLK(m)  block device?
 *    S_ISFIFO(m) FIFO (named pipe)?
 *    S_ISLNK(m)  symbolic link? (Not in POSIX.1-1996.)
 *    S_ISSOCK(m) socket? (Not in POSIX.1-1996.)
 *
 */
	PRI_O(s.st_mode);    /* protection */

	if (S_ISREG(m))
	{
		printf("-");
	}
	else if (S_ISDIR(m))
	{
		printf("d");
	}
	else if (S_ISCHR(m))
	{
		printf("c");
	}
	else if (S_ISBLK(m))
	{
		printf("b");
	}
	else if (S_ISFIFO(m))
	{
		printf("p");
	}
	else if (S_ISLNK(m))
	{
		printf("l");
	}
	else if (S_ISSOCK(m))
	{
		printf("s");
	}

	#else
    /*
	 *S_IFMT     0170000   bitmask for the file type bitfields
	 *S_IFSOCK   0140000   socket
	 *S_IFLNK    0120000   symbolic link
	 *S_IFREG    0100000   regular file
	 *S_IFBLK    0060000   block device
	 *S_IFDIR    0040000   directory
	 *S_IFCHR    0020000   character device
	 *S_IFIFO    0010000   FIFO
     */

	/*printf("m : %#o\n", m);*/
	if ((m & S_IFMT) == S_IFSOCK)
	{
		putchar('s');
	}
	else if ((m & S_IFMT) == S_IFLNK)
	{
		putchar('l');
	}
	else if ((m & S_IFMT) == S_IFREG)
	{
		putchar('-');
	}
	else if ((m & S_IFMT) == S_IFBLK)
	{
		putchar('b');
	}
	else if ((m & S_IFMT) == S_IFDIR)
	{
		putchar('d');
	}
	else if ((m & S_IFMT) == S_IFCHR)
	{
		putchar('c');
	}
	else if ((m & S_IFMT) == S_IFIFO)
	{
		putchar('p');
	}
	#endif

	//file own mode
	//r
	if ((m & S_IRUSR) == S_IRUSR)
	{
		putchar('r');
	}
	else
	{
		putchar('-');
	}
	//w
	if ((m & S_IWUSR) == S_IWUSR)
	{
		putchar('w');
	}
	else
	{
		putchar('-');
	}
	//x
	if ((m & S_IXUSR) == S_IXUSR)
	{
		putchar('x');
	}
	else
	{
		putchar('-');
	}

	//属组
	if ((m & S_IRGRP) == S_IRGRP)
	{
		putchar('r');
	}
	else
	{
		putchar('-');
	}
	//w
	if ((m & S_IWGRP) == S_IWGRP)
	{
		putchar('w');
	}
	else
	{
		putchar('-');
	}
	//x
	if ((m & S_IXGRP) == S_IXGRP)
	{
		putchar('x');
	}
	else
	{
		putchar('-');
	}

	//other user
	//r
	if ((m & S_IROTH) == S_IROTH)
	{
		putchar('r');
	}
	else
	{
		putchar('-');
	}
	//w
	if ((m & S_IWOTH) == S_IWOTH)
	{
		putchar('w');
	}
	else
	{
		putchar('-');
	}
	//x
	if ((m & S_IXOTH) == S_IXOTH)
	{
		putchar('x');
	}
	else
	{
		putchar('-');
	}

	printf("\n");
	return 0;
ERR1:
	return -1;
}
