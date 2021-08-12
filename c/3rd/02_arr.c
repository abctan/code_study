#include <stdio.h>
#include <string.h>

#define MAX 10

//定义结构体类型
struct cls_t {
	char name[64];
	int age;
};

int main(void)
{
	int i;
	//定义变量
	struct cls_t cls[MAX] = {{"tom", 18},{"jim", 19}, {"mary", 20}};
	struct cls_t *new = NULL;
	
	new = cls;

	for (i = 0; i < 3; i++)
	{
		/*printf("name : %s age : %d\n", cls[i].name, cls[i].age);*/
		/*printf("name : %s age : %d\n", new[i].name, new[i].age);*/
		printf("name : %s age : %d\n", (new + i)->name, (new + i)->age);
		/*printf("name : %s age : %d\n", (cls + i)->name, (cls+ i)->age);*/
	}
	return 0;
}








