#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int ret;
	char ch[8];

	system("stty -echo -icanon");
	
    /*
	 *获取键盘键值
	 *ssize_t read(int fd, void *buf, size_t count);
	 *第一个参数：表示文件描述符 0
	 *第二个参数：表示数据存储空间地址
	 *第三个参数：表示空间大小
	 *返回值：
	 *    表示获取数据个数
     */

	while(1)
	{
		ret = read(0, ch, 8);
		if (ret == -1)
		{
			printf("read false!\n");
			return -1;
		}
		else if (ret == 1)
		{
			if (ch[0] == 27)
			{
				break;
			}
			printf("%d ", ch[0]);
		}
		else if (ret == 2)
		{
			printf("%d %d ", ch[0], ch[1]);
		}
		else if (ret == 3)
		{
			printf("%d %d %d ", ch[0], ch[1], ch[2]);
		}
		fflush(NULL);
	}

	system("stty echo icanon");
	return 0;
}
