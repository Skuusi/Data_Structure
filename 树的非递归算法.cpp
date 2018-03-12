#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;

//���Ķ��������ʾ����
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
//�������
void InOrder(BiNode* T)
{
	stack<BiNode*> s;
	//һֱ�����ߣ��ҵ�������������
	BiTree t = GoFarLeft(T, s);
	while (t)
	{
		printf("%d ", t->data);//���������ӡ
		if (t->Rchild != NULL)
		{
			//���t�ڵ�������������ô�ظ�����1
			t = GoFarLeft(t->Rchild, s);
		}
		//���tû��������������ջ��ָʾ������ջ��Ԫ��
		else if (!s.empty())
		{
			t = s.top();
			s.pop();
		}
		//���tû��������������ջΪ��
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