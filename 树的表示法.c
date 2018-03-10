#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ķ��������ʾ����
typedef struct BiNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

//�������������ʾ����
typedef struct TriNode
{
	int data;
	struct BiNode *Lchild, *Rchild;
	struct TriNode* parent;
}TriNode, *TriTree;

//˫������
#define MAX_TREE_SIZE 100
typedef struct BPNode
{
	int data;
	int* parent;//ָ��˫�׵�ָ��
	char LRTag;//���Һ��ӱ�־��
}BPNode;

typedef struct BPTree
{
	BPNode nodes[100];//��Ϊ�ڵ��Ƿ�ɢ�ģ���Ҫ�ѽڵ�洢��������
	int num_node;//�ڵ���Ŀ
	int root;//���ڵ�λ�ã�ע�����洢���Ǹ��׽ڵ���������±�
}BPTree;

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
	/******************************************************/
	BiTree p1, p2, p3, p4, p5;
	p1 = (BiTree)malloc(sizeof(BiNode));
	p2 = (BiTree)malloc(sizeof(BiNode));
	p3 = (BiTree)malloc(sizeof(BiNode));
	p4 = (BiTree)malloc(sizeof(BiNode));
	p5 = (BiTree)malloc(sizeof(BiNode));
	memset(p1, 0, sizeof(BiNode));
	memset(p2, 0, sizeof(BiNode));
	memset(p3, 0, sizeof(BiNode));
	memset(p4, 0, sizeof(BiNode));
	memset(p5, 0, sizeof(BiNode));
	p1->data = 1;
	p2->data = 1;
	p3->data = 1;
	p4->data = 1;
	p5->data = 1;

	p1->Lchild = p2;//			t1
	p1->Rchild = p3;//		t2		t3
	p2->Lchild = p4;//	t4				t5
	p3->Rchild = p5;

	system("pause");
	return 0;
}