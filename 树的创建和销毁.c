#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//树的二叉链表表示方法
typedef struct BiNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

//#法创建树
//按给定的先序序列建立二叉链表
BiNode* BiTree_Creat()
{
	BiNode* tmp = NULL;
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
	{
		return NULL;
	}
	else
	{
		tmp = (BiNode*)malloc(sizeof(BiNode));
		if (tmp == NULL)
		{
			return NULL;
		}
		tmp->data = ch;//生成根节点
		tmp->Lchild = BiTree_Creat();//构建左子树
		tmp->Rchild = BiTree_Creat();//构建右子树
		return tmp;
	}
}

/*
BiNode* CreateBiTree(BiNode* T)
{
BiNode* node = NULL;
BiNode* pL = NULL;
BiNode* pR = NULL;
char h;
scanf_s("%c", &h);
if (h = '#')
{
T = NULL;
}
else
{
node = (BiNode*)malloc(sizeof(BiNode));
memset(node, 0, sizeof(BiNode));
node->data = h;
//递归创建左子树
pL = CreateBiTree(T->Lchild);
if (pL != NULL)
{
node->Lchild = pL;
}
else
{
node->Lchild = NULL;
}
//递归创建右子树
pR = CreateBiTree(T->Rchild);
if (pR != NULL)
{
node->Rchild = pR;
}
else
{
node->Rchild = NULL;
}
}
return node;
}
*/

//销毁树:使用后序遍历
void  BiTree_Free(BiNode* T)
{
	BiNode *tmp = NULL;
	if (T != NULL)
	{
		if (T->Rchild != NULL) BiTree_Free(T->Rchild);
		if (T->Lchild != NULL) BiTree_Free(T->Lchild);
		if (T != NULL)
		{
			free(T);
			T = NULL;
		}
	}
}

/*
void FreeTree(BiNode* T)
{
	if (T == NULL)
	{
		return;
	}
	if (T->Lchild != NULL)
	{
		FreeTree(T->Lchild);
		T->Lchild = NULL;
	}
	if (T->Rchild != NULL)
	{
		FreeTree(T->Rchild);
		T->Rchild = NULL;
	}
	if (T != NULL)
	{
		free(T);
		T = NULL;
	}
}
*/

//先序遍历
void preOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c", root->data);//遍历根
	preOrder(root->Lchild);//遍历左子树
	preOrder(root->Rchild);//遍历右子树
}

int main()
{
	//#法创建树
	printf("请输入先序序列：");
	BiNode* tree = NULL;
	tree = BiTree_Creat();
	//tree = CreateBiTree(tree);
	preOrder(tree);
	printf("\n");

	BiTree_Free(tree);
	printf("树释放完毕\n");

	system("pause");
	return 0;
}