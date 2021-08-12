#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union cls_t{
	char name;
	int age;
};


int main(void)
{
	union cls_t cls;
	union cls_t *p = NULL;

	p = &cls;

	memset(&cls, 0, sizeof(cls));

	cls.name = 'A';

	printf("sizeof(cls) : %d\n", sizeof(cls));

	printf("cls : %p\n", &cls);
	printf("name : %c %p\n", cls.name, &cls.name);
	printf("age : %d %p\n", cls.age, &cls.age);

	printf("p->name : %c\n", p->name);
	return 0;
}
