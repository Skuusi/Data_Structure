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

//计算叶子数方法1 //先序遍历计算节点数
int sum = 0;//尽量不使用全局变量
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
//计算叶子数方法2
void countLeaf2(BiNode* T,int* sum)
{
	if (T != NULL)
	{
		//先序遍历计算节点数
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

//求树的高度
int getDepth(BiNode* root)
{
	int leftDepth = 0, rightDepth = 0, depthVal = 0;
	if (root == NULL)
	{
		depthVal = 0;
		return depthVal;
	}
	//求左子树高度
	leftDepth = getDepth(root->Lchild);
	//求右子树高度
	rightDepth = getDepth(root->Rchild);
	//树高度
	depthVal = 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
	return depthVal;
}

//树的拷贝
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

//#法创建树
//按给定的先序序列建立二叉链表
BiNode* BiTree_Creat()
{
	BiNode* tmp = NULL;
	char ch;
	printf("请输入先序序列：");
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
	printf("\n");

	//计算叶子数方法1
	countLeaf(&t1);
	printf("countLeaf:%d\n", sum);

	//计算叶子数方法2
	int mysum = 0;
	countLeaf2(&t1, &mysum);
	printf("countLeaf2:%d\n", mysum);

	//求树的高度
	printf("树的高度:%d\n", getDepth(&t1));

	//树的拷贝
	BiNode* newTree = NULL;
	newTree = copyTree(&t1);
	printf("树的拷贝：\n");
	inOrder(newTree);
	printf("\n");

	//#法创建树
	BiNode* tree = NULL;
	tree = BiTree_Creat();
	//tree = CreateBiTree(tree);
	preOrder(&t1);
	printf("\n");

	system("pause");
	return 0;
}