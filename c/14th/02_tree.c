#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

//实现树结构
//定义树节点信息
struct tree_t{
	int data;	//表示数据
	struct tree_t *right;//右孩子 右子树
	struct tree_t *left;//左孩子  左子树
};

//实现插入函数
int insert(int num, struct tree_t **root)
{
	struct tree_t *new = NULL;
	struct tree_t *tail = *root;

	new = (struct tree_t *)malloc(sizeof(struct tree_t));
	if (NULL == new)
	{
		printf("malloc new false!\n");
		return -1;
	}

	//树节点信息
	new->data = num;
	new->right = NULL;
	new->left = NULL;
	
	if (*root == NULL)
	{
		*root = new;
	}
	else
	{
		while(1)
		{
			if (new->data >= tail->data)
			{
				if (tail->right == NULL)
				{
					tail->right = new;
					return 0;
				}
				tail = tail->right;
			}
			else if (new->data < tail->data)
			{
				if (tail->left == NULL)
				{
					tail->left = new;
					return 0;
				}
				tail = tail->left;
			}

		}
	}
	return 0;
}

void fir(struct tree_t *root)
{
	if (root == NULL)
	{
		return ;
	}
	printf("%d ", root->data);
	fir(root->left);//左孩子
	fir(root->right);//右孩子
}

//中序
void mid(struct tree_t *root)
{
	if (root == NULL)
	{
		return ;
	}
	mid(root->left);
	printf("%d ", root->data);
	mid(root->right);
}

//后序
void end(struct tree_t *root)
{
	if (root == NULL)
	{
		return ;
	}

	end(root->left);
	end(root->right);
	printf("%d ", root->data);
}

//层次变量
void lev(struct tree_t *root)
{
	//定义队列
	struct tree_t *queue[MAX];
	
	int front = 0;
	int end = 0;

	queue[end++] = root;
	while(front != end)
	{
		root = queue[front++];	
		printf("%d ", root->data);
		if (root->left != NULL)
			queue[end++] = root->left;
		if (root->right != NULL)
			queue[end++] = root->right;
	}
}

//结构打印
void show(struct tree_t *root)
{
	int i;
	static int count  = 0;
	if (root == NULL)
	{
		return ;
	}

	count++;
	show(root->right);
	count--;

	for (i = 0; i < count; i++)
	{
		printf("\t");
	}
	printf("%d\n", root->data);

	count++;
	show(root->left);
	count--;
}

struct tree_t *max(struct tree_t *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root;
}
struct tree_t *min(struct tree_t *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

int count(struct tree_t *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return count(root->left) + count(root->right) + 1;
}

int depth(struct tree_t *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return (depth(root->left) > depth(root->right)) ?  depth(root->left) + 1: depth(root->right) + 1;
}

//查找
struct tree_t *find(int key, struct tree_t *root)
{
	struct tree_t *tail = root;


	if (root == NULL)
	{
		return NULL;
	}

	while(1)
	{
		if (key > tail->data)
		{
			if (tail->right == NULL)
			{
				return NULL;
			}
			tail = tail->right;
		}
		else if (key < tail->data)
		{
			if (tail->left == NULL)
			{
				return NULL;
			}
			tail = tail->left;
		}
		else
		{
			return tail;
		}
	}
}

//删除
void del(int key, struct tree_t **root)
{
	struct tree_t *tail = *root;
	struct tree_t *parent = NULL;
	struct tree_t *l = NULL, *r = NULL, *new = NULL;
	
	if (*root == NULL)
	{
		return ;
	}

	while(1)
	{
		if (key > tail->data)
		{
			parent = tail;
			if (tail->right == NULL)
			{
				return ;
			}
			tail = tail->right;
		}
		else if (key < tail->data)
		{
			parent = tail;
			if (tail->left == NULL)
			{
				return ;
			}
			tail = tail->left;
		}
		else
		{
			break;
		}
	}
    /*
	 *printf("parent : %d\n", parent->data);
	 *printf("key : %d\n", tail->data);
     */
	 printf("hello!\n");
	//tail 
	l = tail->left;
	r = tail->right;

	if (l != NULL && r == NULL)
	{
		new = l;
	}
	if (l == NULL && r != NULL)
	{
		new = r;
	}
	if (l != NULL && r != NULL)
	{
		#if 1
		//l => r
		min(r)->left = l;
		new = r;
		#else
		// r => l
		max(l)->right = r;
		new = l;
		#endif
	}

	if (key == (*root)->data)
	{
		*root = new;	
	}
	else
	{
		if (key > parent->data)
		{
			parent->right = new;
		}
		else
		{
			parent->left = new;
		}
	}
	free(tail);
}


//求最大数 最小数 深度 个数 查找 删除
int main(void)
{
	int i;
	int num;
	struct tree_t *root = NULL;//定义一个空树
	int ret;
	int key;
	
	/*srand(time(NULL));*/

	for (i = 0; i < MAX; i++)
	{
		num = rand() % 100;
		printf("%d ", num);
		//把数据保存到树中
		ret = insert(num, &root);
		if (ret == -1)
		{
			printf("insert false!\n");
			return -1;
		}
	}
	printf("\n");

    /*
	 *printf("fir : ");
	 *fir(root);
	 *printf("\n");
	 *printf("mid : ");
	 *mid(root);
	 *printf("\n");
	 *printf("end : ");
	 *end(root);
	 *printf("\n");
	 *printf("lev : ");
	 *lev(root);
	 *printf("\n");
     */


	printf("==================\n");
	show(root);
	printf("==================\n");
    /*
	 *printf("max : %d\n", max(root)->data);
	 *printf("min : %d\n", min(root)->data);
	 *printf("count : %d\n", count(root));
	 *printf("depth : %d\n", depth(root));
     */


	printf("please input del key : ");
	scanf("%d", &key);
	del(key, &root);
	/*printf("find = %d\n", find(key, root)->data);*/
	printf("==================\n");
	show(root);
	printf("==================\n");


	return 0;
}
