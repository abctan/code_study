#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	char ch;
	int ret;
	/*close(2);*/

	/*fd = open(argv[1], O_RDONLY);*/
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		perror("open");
		return -1;
	}

	printf("fd : %d\n", fd);

	//写数据到文件中
	ret = write(fd, "hello", 5);
	if (ret == -1)
	{
		printf("write false!\n");
		return -1;
	}

	printf("write success!\n");


	//获取文件中数据
/*
 *    ret = read(fd, &ch, 1);
 *    if (ret <= 0)
 *    {
 *        printf("read false!\n");
 *        return -1;
 *    }
 *
 *    printf("ch : %c\n", ch);
 */
	close(fd);
	return 0;
}
