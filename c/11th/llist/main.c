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

//比较函数
int cmp_name(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct cls_t *)d2)->name);
}
int sort_name(void *d1, void *d2)
{
	return strcmp(((struct cls_t *)d1)->name, ((struct cls_t *)d2)->name);
}

int cmp_age(void *d1, void *d2)
{
	return *(int *)d1 - ((struct cls_t *)d2)->age;
}
int sort_age(void *d1, void *d2)
{
	return ((struct cls_t *)d1)->age - ((struct cls_t *)d2)->age;
}
int cmp_sex(void *d1, void *d2)
{
	return *(char *)d1 - ((struct cls_t *)d2)->sex;
}
int sort_sex(void *d1, void *d2)
{
	return ((struct cls_t *)d1)->sex - ((struct cls_t *)d2)->sex;
}

int main(int argc, char *argv[])
{
	int i;
	struct cls_t cls, stu = {"zhang san", 20, 'M'};
	LLIST *handle = NULL;
	int index;
	char name[64];


	if (argc >= 2)
	{
		printf("load!\n");
		handle = llist_load("./stu.db");
		llist_travel_next(handle, ls);
	}
	else
	{
		//初始化
		handle = llist_creat(sizeof(struct cls_t));
		if (handle == NULL)
		{
			return -1;
		}

		for (i = 0; i < MAX; i++)
		{
			snprintf(cls.name, sizeof(cls.name), "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
			cls.age = rand() % 3 + 18;
			cls.sex = "MF"[rand()% 2];
			
			//尾插
			llist_insert_end(&cls, handle);
			/*llist_insert_first(&cls, handle);*/
		}


		//遍历
		llist_travel_next(handle, ls);
		printf("=============\n");
		llist_sort_asc(sort_name, handle);
		llist_travel_next(handle, ls);
		llist_store("./stu.db", handle);
		printf("sizeof(struct cls_t) = %d\n", sizeof(struct cls_t));

		/*llist_travel_prev(handle, ls);*/
		/*
		 *printf("please input find index : ");
		 *scanf("%d", &index);
		 *ls(llist_find_index(index, handle));
		 */

		/*llist_insert_index(&stu, index, handle);*/

		/*GETLINES("please input del name : ", name);*/
		/*llist_del_end(name, cmp_name, handle);*/
		/*
		 *int age;
		 *printf("please input del age : ");
		 *scanf("%d", &age);
		 */
		/*llist_del_end(&age, cmp_age, handle);*/
		/*llist_del_first(&age, cmp_age, handle);*/
		/*llist_del_index(age, handle);*/
		/*llist_del_all(&age, cmp_age, handle);*/
		/*llist_travel_next(handle, ls);*/
		printf("count : %d\n", llist_num(handle));
	}
	//销毁
	llist_destroy(handle);
}
