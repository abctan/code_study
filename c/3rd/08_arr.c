#include <stdio.h>

int main(void)
{
	char buf[] = "abcdefg";

	while(1)
	{
		putchar("abcdefg"[rand() % 7]);
		fflush(NULL);
		sleep(1);
	}
	return 0;
}
