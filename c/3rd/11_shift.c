#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cls_t{
	char name[64];
	int age;
};
int main(void)
{
	void *p = NULL;

	printf("p = %p p + 1 = %p\n", p, p + 1);
	return 0;
}
