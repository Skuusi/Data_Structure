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

	system("pause");
	return 0;
}