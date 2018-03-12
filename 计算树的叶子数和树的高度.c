#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ķ��������ʾ����
typedef struct BiNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

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
void countLeaf2(BiNode* T, int* sum)
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

	//����Ҷ��������1
	countLeaf(&t1);
	printf("countLeaf:%d\n", sum);

	//����Ҷ��������2
	int mysum = 0;
	countLeaf2(&t1, &mysum);
	printf("countLeaf2:%d\n", mysum);

	//�����ĸ߶�
	printf("���ĸ߶�:%d\n", getDepth(&t1));

	system("pause");
	return 0;
}