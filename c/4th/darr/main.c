#include "darr.h"

struct cls_t{
	char name[64];
	int age;
	int id;
	char sex;
	float cn;
	float en;
	float result;
};


#define MAX 10


void ls(void *data)
{
	struct cls_t *new = (struct cls_t *)data;

		printf("name : %s age : %d id : %d sex : %c cn : %.2f en : %.2f result : %.2f\n",
			new->name, new->age, new->id, new->sex, new->cn, new->en, new->result);

}

void ls_int(void *data)
{
	printf("%d ", *(int *)data);
}


int main(void)
{
	int i;
	struct cls_t cls;
	int num;
	DARR *handle = NULL;

	/*handle = darr_creat(sizeof(struct cls_t));*/
	handle = darr_creat(sizeof(int));
	if (handle == NULL)
	{
		printf("darr_creat false!\n");
		return -1;
	}

	for (i = 0; i < MAX; i++)
	{
        /*
		 *snprintf(cls.name, sizeof(cls.name), "cls_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		 *cls.age = rand() % 3 + 18;
		 *cls.id = rand() % 100 + 10000;
		 *cls.sex = "MF"[rand() % 2];
		 *cls.cn = rand() % 30 + 70;
		 *cls.en = rand() % 20 + 80;
		 *cls.result = cls.cn + cls.en;
         */
		num = rand() % 100;
		//插入函数实现 函数调用
		/*darr_append(&cls, handle);*/
		darr_append(&num, handle);

	}

	//遍历
	darr_travel(handle, ls_int);
		
	//销毁	
	darr_destroy(handle);
	return 0;
}
