#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ķ��������ʾ����
typedef struct BiNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

//#��������
//���������������н�����������
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
		tmp->data = ch;//���ɸ��ڵ�
		tmp->Lchild = BiTree_Creat();//����������
		tmp->Rchild = BiTree_Creat();//����������
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
//�ݹ鴴��������
pL = CreateBiTree(T->Lchild);
if (pL != NULL)
{
node->Lchild = pL;
}
else
{
node->Lchild = NULL;
}
//�ݹ鴴��������
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

//������:ʹ�ú������
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

//�������
void preOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c", root->data);//������
	preOrder(root->Lchild);//����������
	preOrder(root->Rchild);//����������
}

int main()
{
	//#��������
	printf("�������������У�");
	BiNode* tree = NULL;
	tree = BiTree_Creat();
	//tree = CreateBiTree(tree);
	preOrder(tree);
	printf("\n");

	BiTree_Free(tree);
	printf("���ͷ����\n");

	system("pause");
	return 0;
}