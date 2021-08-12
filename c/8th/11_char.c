#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(void);

int main(void)
{

	printf("main : line : %d : %s : %s\n", __LINE__, __func__, __FILE__);
	printf("time : %s\n", __TIME__);
	printf("date : %s\n", __DATE__);
	test();
	return 0;
}
void test(void)
{
	printf("test : line = %d : %s : %s\n", __LINE__, __func__, __FILE__);
}
