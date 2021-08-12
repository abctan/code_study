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

int main(int argc, char *argv[])
{
	int i = 0;
	struct group *grp = NULL;

	ERRP((grp = getgrnam(argv[1])) == NULL, getgrnam, goto ERR1);


	/*printf("gid : %d\n", grp->gr_gid);*/
	while(1)
	{
		if (grp->gr_mem[i] == NULL)
		{
			return -1;
		}
		printf("%s\n", grp->gr_mem[i]);
		i++;
	}
	return 0;
ERR1:
	return -1;
}
