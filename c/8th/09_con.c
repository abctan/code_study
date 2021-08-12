#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define A 0
#define B 0
#define C 1
#define D 0

int main(void)
{

	#if 0
		#if A
		printf("hello!\n");
		#else
		printf("world!\n");
		#endif
	#endif

	#if A
	printf("AAAAA!\n");
	#elif B
	printf("BBBBB!\n");
	#elif C
	printf("CCCCC!\n");
	#else
	printf("DDDDD!\n");
	#endif
	return 0;
}
