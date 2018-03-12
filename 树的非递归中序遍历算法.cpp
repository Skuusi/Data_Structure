#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;

//树的二叉链表表示方法
typedef struct BiNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

BiNode* GoFarLeft(BiNode* T, stack<BiNode*> &s)
{
	if (T == NULL)
	{
		return NULL;
	}
	while (T->Lchild)
	{
		s.push(T);
		T = T->Lchild;
	}
	return T;
}
//中序遍历
void InOrder(BiNode* T)
{
	stack<BiNode*> s;
	//一直往左走，找到中序遍历的起点
	BiTree t = GoFarLeft(T, s);
	while (t)
	{
		printf("%d ", t->data);//中序遍历打印
		if (t->Rchild != NULL)
		{
			//如果t节点有右子树，那么重复步骤1
			t = GoFarLeft(t->Rchild, s);
		}
		//如果t没有右子树，根据栈顶指示，访问栈顶元素
		else if (!s.empty())
		{
			t = s.top();
			s.pop();
		}
		//如果t没有右子树，并且栈为空
		else
		{
			t = NULL;
		}
	}
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

	InOrder(&t1);

	system("pause");
	return 0;
}
