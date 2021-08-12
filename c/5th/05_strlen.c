#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char s[5] = {'h', 'e', 'l', 'l', 'o'};

	//sizeof : 是求空间大小
	//strlen : 是求字符串长度
	printf("sizeof(s) = %d\n", sizeof(s));//64  |45| 65 |66 | 
	printf("strlen(s) = %d\n", strlen(s));//5 63 
	return 0;
}
