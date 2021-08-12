//表示输入输出头文件
#include <stdio.h>
//str家族函数头文件 strcpy strcat strcmp strchr strlen memcpy ...
#include <string.h>
//申请内存空间头文件 malloc calloc realloc
#include <stdlib.h>

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
	int count = 0;
	struct cls_t cls;

	while(1)
	{
		printf("please input %d name : ", count + 1);
		scanf("%s", cls.name);

		//退出条件 exit
		if (strcmp(cls.name, "exit") == 0)
		{
			break;
		}
		printf("please input %d age : ", count + 1);
		scanf("%d", &cls.age);

		printf("please input %d id : ", count + 1);
		scanf("%d", &cls.id);
		getchar();
		printf("please input %d sex : ", count + 1);
		scanf("%c", &cls.sex);
		printf("please input %d cn : ", count + 1);
		scanf("%f", &cls.cn);
		printf("please input %d en : ", count + 1);
		scanf("%f", &cls.en);

		/*printf("name : %s\n", cls.name);*/

		count++;
	}
		
	return 0;
}









