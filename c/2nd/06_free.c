#include <stdio.h>

int main(void)
{
	int *p = NULL;

	free(p);
	free(p);
	free(p);
	free(p);
	free(p);
	free(p);
	free(p);
	return 0;
}
