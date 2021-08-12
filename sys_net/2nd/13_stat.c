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

	ret = stat(argv[1], &s);
	if (ret == -1)
	{
		printf("stat false!\n");
		goto ERR1;
	}

	PRI_D(s.st_dev);     /* ID of device containing file */
	PRI_D(s.st_ino);     /* inode number */
	PRI_O(s.st_mode);    /* protection */
	PRI_D(s.st_nlink);   /* number of hard links */
	PRI_D(s.st_uid);     /* user ID of owner */
	PRI_D(s.st_gid);     /* group ID of owner */
	PRI_D(s.st_rdev);    /* device ID (if special file) */
	PRI_D(s.st_size);    /* total size, in bytes */
	PRI_D(s.st_blksize); /* blocksize for filesyPRI_O(s.stem I/O */
	PRI_D(s.st_blocks);  /* number of blocks allocated */
	PRI_D(s.st_atime);   /* time of laPRI_O(s.st access */
	PRI_D(s.st_mtime);   /* time of laPRI_O(s.st modification */
	PRI_D(s.st_ctime);   /* time of laPRI_O(s.st PRI_O(s.status change */
	return 0;
ERR1:
	return -1;
}
