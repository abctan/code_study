#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cls_t{
	char *name;//64
	int age;
};

int main(void)
{
	struct cls_t *cls = NULL;

	cls = (struct cls_t *)malloc(sizeof(struct cls_t));
	if (NULL == cls)
	{
		printf("malloc false!\n");
		return -1;
	}

	cls->name = (char *)malloc(sizeof(char) * 64);
	if (NULL == cls->name)
	{
		printf("malloc name false!\n");
		free(cls);
		return -1;
	}
	strcpy(cls->name, "zhangsan");

	printf("name : %s\n", cls->name);


	free(cls->name);
	free(cls);
	return 0;
}
