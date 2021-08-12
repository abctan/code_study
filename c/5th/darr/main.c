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

		printf("name : %6s age : %d id : %d sex : %c cn : %.2f en : %.2f result : %.2f\n",
			new->name, new->age, new->id, new->sex, new->cn, new->en, new->result);

}

int cmp_name(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct cls_t *)d2)->name);
}
int cmp_age(void *d1, void *d2)
{
	return *(int *)d1 - ((struct cls_t *)d2)->age;
}



int main(void)
{
	int i;
	struct cls_t cls, stu = {"tom", 18, 10001, 'M', 88.88, 99.99, 88.88 + 99.99};
	DARR *handle = NULL;
	int index;
	char name[64];

	handle = darr_creat(sizeof(struct cls_t));
	if (handle == NULL)
	{
		printf("darr_creat false!\n");
		return -1;
	}

	for (i = 0; i < MAX; i++)
	{
		snprintf(cls.name, sizeof(cls.name), "cls_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		cls.age = rand() % 3 + 18;
		cls.id = rand() % 100 + 10000;
		cls.sex = "MF"[rand() % 2];
		cls.cn = rand() % 30 + 70;
		cls.en = rand() % 20 + 80;
		cls.result = cls.cn + cls.en;
		//插入函数实现 函数调用
		/*darr_append(&cls, handle);*/
		darr_appprev(&cls, handle);

	}

	//遍历
	darr_travel(handle, ls);
	printf("num : %d\n", darr_num(handle));
	
/*
 *    printf("please input del name : ");
 *    fgets(name, sizeof(name), stdin);
 *    if (name[strlen(name) - 1] == '\n')
 *        name[strlen(name) - 1] = '\0';
 *
 *    darr_del_first(name, cmp_name, handle);
 */
	int age;
	printf("please input del age : ");
	scanf("%d", &age);
	darr_del_first(&age, cmp_age, handle);
	darr_travel(handle, ls);
	printf("num : %d\n", darr_num(handle));



    /*
	 *printf("please input index : ");
	 *scanf("%d", &index);
	 *darr_index_insert(&stu, index, handle);
	 *darr_travel(handle, ls);
     */

	//销毁	
	darr_destroy(handle);
	return 0;
}
