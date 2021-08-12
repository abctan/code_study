#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char dest[128] = "world";
	char src[128] = "hello";

    /*
	 *memmove : 内存重叠时候使用
	 *memcpy  : 不同内存空间拷贝
     */
	/*memset(dest, 0, sizeof(dest));*/

	/*memcpy(dest, src, strlen(src) + 1);*/
	//wo rld
	//hel lo
	//wolo
	/*memmove(dest + 2, src + 3, strlen(src) + 1);*/
	//hel lo src + 3
	//he llo src + 2
	//helllo
	/*memcpy(src + 3, src + 2, strlen(src) + 1);*/
	memmove(src + 3, src + 2, strlen(src) + 1);

	/*printf("dest : %s\n", dest);*/
	printf("src : %s\n", src);
	return 0;
}
