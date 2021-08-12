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

struct op_t{
	int num;
	char name[256];
};
void my_tree(const char *path)
{
	DIR *dir = NULL;
	struct dirent *dp = NULL;
	static int count = 0;
	int i;
	struct op_t op;

	/*printf("pwd : %s\n", get_current_dir_name());*/

	dir = opendir(path);
	if (dir == NULL)
	{
		goto ERR1;
	}
	chdir(path);
	/*ERRP(dir == NULL, opendir, goto ERR1);*/


	while(1)
	{
		dp = readdir(dir);
		if (dp == NULL)
		{
			/*printf(".-- %s\n", op.name);*/
			break;
		}

		if (dp->d_name[0] == '.')
		{
			continue;
		}
		for (i = 0; i < count; i++)
		{
			printf("|   ");
		}

		op.num++;
		strcpy(opop.name>d_name);
		printf("|--%s\n", op.name);
		if (dp->d_type == 4)
		{
			count++;
			/*printf("pwd : %s\n", get_current_dir_name());*/
			my_tree(dp->d_name);
			count--;
		}
	}
	chdir("..");

	closedir(dir);
	return ;
ERR1:
	return ;
}

int main(int argc, char *argv[])
{
	struct stat s;

	ERRP(stat(argv[1], &s) == -1, stat, goto ERR1);
	
	if (S_ISDIR(s.st_mode))
	{
		my_tree(argv[1]);
	}

	return 0;
ERR1:
	return -1;
}
