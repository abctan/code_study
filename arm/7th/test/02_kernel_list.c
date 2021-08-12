#include <stdio.h>

struct cls_t{
	char name[128];
	char sex;
	int age;
};

int main(int argc, char *argv[])
{
	struct cls_t cls = {.name = "tom", .age = 18, .sex = 'M'};
	struct cls_t *p = NULL;
	int len = 0;

	len = (unsigned int)(&(((struct cls_t *)0)->age));

	 p = (struct cls_t *)((char *)&cls.age - (unsigned int)(&(((struct cls_t *)0)->age)));
	printf("len : %d\n", len);
	printf("name : %s\n", p->name);
	printf("sex : %c\n", p->sex);
	// age => address => struct cls
	// &cls.age => name sex age
	//&cls => name age sex

/*
 *    printf("name : %p\n", cls.name);
 *    printf("age : %p\n", &cls.age);
 *    printf("sex : %p\n", &cls.sex);
 *
 *    p = (struct cls_t *)((char *)&cls.age - 128);
 *    printf("name : %s\n", p->name);
 *    printf("sex : %c\n", p->sex);
 */
    /*
	 *printf("name : %s\n", (char *)(&cls.age - 32));
	 *printf("sex : %c\n", *(char *)(&cls.age + 1));
     */
	return 0;
}
