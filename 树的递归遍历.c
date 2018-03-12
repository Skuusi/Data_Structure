#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//树的二叉链表表示方法
typedef struct BiNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

//先序遍历
void preOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d", root->data);//遍历根
	preOrder(root->Lchild);//遍历左子树
	preOrder(root->Rchild);//遍历右子树
}
//中序遍历
void inOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->Lchild);//遍历左子树
	printf("%d", root->data);//遍历根
	inOrder(root->Rchild);//遍历右子树
}
//后序遍历
void postOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->Lchild);//遍历左子树
	postOrder(root->Rchild);//遍历右子树
	printf("%d", root->data);//遍历根
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

	//树的遍历
	preOrder(&t1);
	printf("\n");
	inOrder(&t1);
	printf("\n");
	postOrder(&t1);

	system("pause");
	return 0;
}
