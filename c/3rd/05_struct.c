//表示输入输出头文件
#include <stdio.h>
//str家族函数头文件 strcpy strcat strcmp strchr strlen memcpy ...
#include <string.h>
//申请内存空间头文件 malloc calloc realloc
#include <stdlib.h>


#define MAX 10

//定义学生结构体类型
struct cls_t{
	char name[64];
	int age;
	int id;
	char sex;
	float cn;
	float en;
	//=======
};


int main(void)
{
	int i;
	int count = 0;
	struct cls_t cls;

	//rand() 随机数
	//int snprintf(char *str, size_t size, const char *format, ...);
	// 第一个参数：表示空间地址
	// 第二个参数：表示空间大小
	// 第三个参数：表示格式 %s %d %c %f %p %x ...
	// ...		   表示可变参 对格式补充	
	for (i = 0; i < MAX; i++)
	{
		snprintf(cls.name, sizeof(cls.name), "cls_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		cls.age = rand() % 3 + 18;
		cls.id = rand() % 100 + 10000;
		cls.sex = "MF"[rand() % 2];
		cls.cn = rand() % 30 + 70;
		cls.en = rand() % 20 + 80;

		printf("name : %s age : %d id : %d sex : %c cn : %.2f en : %.2f\n", 
			cls.name, cls.age, cls.id, cls.sex, cls.cn, cls.en);
	}
		
	return 0;
}









