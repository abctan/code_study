#include "llist.h"

#define MAX 10

struct cls_t{
	char name[64];
	int age;
	char sex;
};

void ls(void *data)
{
	struct cls_t *stu = (struct cls_t *)data;

	printf("name : %s | age : %d | sex : %c\n", stu->name, stu->age, stu->sex);

}

int main(void)
{
	int i;
	struct cls_t cls;
	LLIST *handle = NULL;

	//初始化
	handle = llist_creat(sizeof(struct cls_t));
	if (handle == NULL)
	{
		return -1;
	}

	for (i = 0; i < MAX; i++)
	{
		snprintf(cls.name, sizeof(cls.name), "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		cls.age = rand() % 100;
		cls.sex = "MF"[rand()% 2];
		
		//尾插
		llist_insert_end(&cls, handle);
	}

	//遍历
	llist_travel_next(handle, ls);

	//销毁
	llist_destroy(handle);
}
