#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ķ��������ʾ����
typedef struct BiNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

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
	newNode = (BiNode*)malloc(sizeof(BiNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->Lchild = newLptr;
	newNode->Rchild = newRptr;
	newNode->data = root->data;
	return newNode;
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

	//���Ŀ���
	BiNode* newTree = NULL;
	newTree = copyTree(&t1);
	printf("���Ŀ�����\n");
	inOrder(newTree);
	printf("\n");

	system("pause");
	return 0;
}