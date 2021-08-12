#include <stdio.h>
#include <string.h>

//定义结构体类型
struct cls_t {
	char name[64];
	int age;
};

struct stu_t{
	char name[64];
	int age;
};

int main(void)
{
	//定义变量
	struct cls_t cls = {"tom", 18}, cls1 = {};
	struct cls_t *p = &cls;

	printf("cls.name = %s cls.age = %d\n", cls.name, cls.age);
	printf("p->name = %s p->age = %d\n", p->name, p->age);
	printf("name : %s age : %d\n", (&cls)->name, (&cls)->age);
	printf("name : %s age : %d\n", (*p).name, (*p).age);
	return 0;
}








