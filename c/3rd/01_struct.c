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

	struct stu_t stu;

	printf("cls.name = %s cls.age = %d\n", cls.name, cls.age);

	/*cls1 = cls;*/ //yes
	/*stu = cls;//no 类型不匹配*/
	memcpy(&stu, &cls, sizeof(cls));

	/*cls1.name = cls.name;*/ //no

	printf("cls1.name = %s cls1.age = %d\n", cls1.name, cls1.age);
	return 0;
}








