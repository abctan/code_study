#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));

	printf("%d\n", rand() % 4 + 1);
	return 0;
}
