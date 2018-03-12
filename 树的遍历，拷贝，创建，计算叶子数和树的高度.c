#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ķ��������ʾ����
typedef struct BiNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

//�������
void preOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d", root->data);//������
	preOrder(root->Lchild);//����������
	preOrder(root->Rchild);//����������
}
//�������
void inOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->Lchild);//����������
	printf("%d", root->data);//������
	inOrder(root->Rchild);//����������
}
//�������
void postOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->Lchild);//����������
	postOrder(root->Rchild);//����������
	printf("%d", root->data);//������
}

//����Ҷ��������1 //�����������ڵ���
int sum = 0;//������ʹ��ȫ�ֱ���
void countLeaf(BiNode* T)
{
	if (T != NULL)
	{
		if (T->Lchild == NULL && T->Rchild == NULL)
		{
			sum++;
		}
		if (T->Lchild)
		{
			countLeaf(T->Lchild);
		}
		if (T->Rchild)
		{
			countLeaf(T->Rchild);
		}
	}
}
//����Ҷ��������2
void countLeaf2(BiNode* T,int* sum)
{
	if (T != NULL)
	{
		//�����������ڵ���
		if (T->Lchild == NULL && T->Rchild == NULL)
		{
			(*sum)++;
		}
		if (T->Lchild)
		{
			countLeaf2(T->Lchild, sum);
		}
		if (T->Rchild)
		{
			countLeaf2(T->Rchild, sum);
		}
	}
}

//�����ĸ߶�
int getDepth(BiNode* root)
{
	int leftDepth = 0, rightDepth = 0, depthVal = 0;
	if (root == NULL)
	{
		depthVal = 0;
		return depthVal;
	}
	//���������߶�
	leftDepth = getDepth(root->Lchild);
	//���������߶�
	rightDepth = getDepth(root->Rchild);
	//���߶�
	depthVal = 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
	return depthVal;
}

//���Ŀ���
BiNode* copyTree(BiNode* root)
{
	BiNode* newLptr = NULL;
	BiNode* newRptr = NULL;
	BiNode* newNode = NULL;
	if (root->Lchild != NULL)
	{
		newLptr = copyTree(root->Lchild);
	}
	else
	{
		newLptr = NULL;
	}
	if (root->Rchild != NULL)
	{
		newRptr = copyTree(root->Rchild);
	}
	else
	{
		newRptr = NULL;
	}
	newNode =(BiNode*) malloc(sizeof(BiNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->Lchild = newLptr;
	newNode->Rchild = newRptr;
	newNode->data = root->data;
	return newNode;
}

//#��������
//���������������н�����������
BiNode* BiTree_Creat()
{
	BiNode* tmp = NULL;
	char ch;
	printf("�������������У�");
	scanf_s("%c", &ch);
	if (ch = '#')
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

int main()
{
	BiNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.Lchild = &t2;//			t1
	t1.Rchild = &t3;//		t2		t3
	t2.Lchild = &t4;//	t4				t5
	t3.Rchild = &t5;

	//���ı���
	preOrder(&t1);
	printf("\n");
	inOrder(&t1);
	printf("\n");
	postOrder(&t1);
	printf("\n");

	//����Ҷ��������1
	countLeaf(&t1);
	printf("countLeaf:%d\n", sum);

	//����Ҷ��������2
	int mysum = 0;
	countLeaf2(&t1, &mysum);
	printf("countLeaf2:%d\n", mysum);

	//�����ĸ߶�
	printf("���ĸ߶�:%d\n", getDepth(&t1));

	//���Ŀ���
	BiNode* newTree = NULL;
	newTree = copyTree(&t1);
	printf("���Ŀ�����\n");
	inOrder(newTree);
	printf("\n");

	//#��������
	BiNode* tree = NULL;
	tree = BiTree_Creat();
	//tree = CreateBiTree(tree);
	preOrder(&t1);
	printf("\n");

	system("pause");
	return 0;
}