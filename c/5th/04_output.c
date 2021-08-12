#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	fclose(stdout);
	printf("hello world!\n");
	fprintf(stdout, "hello!\n");
	fprintf(stderr, "world!\n");
	return 0;
}
