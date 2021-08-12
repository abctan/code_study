#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>
//获取鼠标事件头文件
#include <linux/input.h>//gf  ctrl + o

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	struct input_event event;

	//打开鼠标
	fd = open("/dev/input/event1", O_RDONLY);
	/*fd = open("/dev/input/mouse0", O_RDONLY);*/
	ERRP(fd == -1, open, goto ERR1);

	
	while(1)
	{
		ret = read(fd, &event, sizeof(event));
		ERRP(ret != sizeof(event), read, goto ERR2);
        /*
		 *sleep(1);
		 *if (event.code == BTN_LEFT)
		 *{
		 *    printf("left!\n");
		 *}
		 *else if (event.code == BTN_RIGHT)
		 *{
		 *    printf("right!\n");
		 *}
		 *printf("type : %d code : %d value : %d\n", event.type, event.code, event.value);
         */
		if (event.type == 1)
		{
			if (event.value == 1)
			{
				printf("hello!\n");
			}
			else
			{
				printf("world!\n");
			}
		}
	}
	close(fd);
	return 0;
ERR2:
	close(fd);
ERR1:
	return -1;
}
