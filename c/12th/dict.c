#include "llist.h"


//电子辞典数据结构体信息
struct dict_t{
	char *cn;//中文
	char *en;//英文
};

LLIST *dict_load(const char *path)
{
	LLIST *handle = NULL;
	FILE *fp = NULL;
	char buf[128];
	int flag = 1; // 0 => cn 1 => en
	struct dict_t new;

	handle = llist_creat(sizeof(struct dict_t));
	ERRP(handle == NULL, "llist_creat", goto ERR1);

	fp = fopen(path, "r");
	ERRP(fp == NULL, "fopen", goto ERR2);

	//按行操作
	while(1)
	{
		
		if (fgets(buf, sizeof(buf), fp) == NULL)
		{
			break;
		}
		buf[strlen(buf) - 1] = '\0';
		if (flag)
		{
			new.en = (char *)malloc(strlen(buf) + 1);
			strcpy(new.en, buf);
			flag = !flag;
		}
		else
		{
			new.cn = (char *)malloc(strlen(buf) + 1);
			strcpy(new.cn, buf);
			flag = !flag;

			llist_insert_end(&new, handle);

		}

		/*printf("%s\n", buf);*/
		/*getchar();*/
	}
	return handle;
ERR2:
	llist_destroy(handle);
ERR1:
	return NULL;
}
void ls(void *data)
{
	struct dict_t *dict = (struct dict_t *)data;

	printf("en : %s cn : %s\n", dict->en, dict->cn);
}
int main(void)
{
	LLIST *handle = NULL;
	handle = dict_load("./ciku.dict");
	ERRP(handle == NULL, "dict_load", goto ERR1);


	llist_travel_next(handle, ls);
	llist_destroy(handle);
	return 0;
ERR1:
	return -1;
}


