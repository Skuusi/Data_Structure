#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

typedef struct Teacher
{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;

int main()
{
	Teacher t1, t2, t3, t4, t5;
	t1.age = 32;
	t2.age = 45;
	t3.age = 25;
	t4.age = 28;
	t5.age = 34;

	//1.�������Ա�
	int ret = 0;
	LinkList* list = NULL;
	list = LinkList_Create();
	if (list == NULL)
	{
		printf("func LinkList_Create() err \n");
	}

	//2.��ȡ���Ա���
	int len = LinkList_Length(list);

	//3.��������
	LinkList_Insert(list, (LinkListNode*) (&t3), 0);//ͷ�巨
	LinkList_Insert(list, (LinkListNode*) (&t1), 0);
	LinkList_Insert(list, (LinkListNode*) (&t2), 0);
	LinkList_Insert(list, (LinkListNode*) (&t4), 0);
	LinkList_Insert(list, (LinkListNode*) (&t5), 0);
	//����
	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teacher* tmp = (Teacher*)LinkList_Get(list, i);
		if (tmp == NULL)
		{
			return;
		}
		printf("tmp->age:%d \n", tmp->age);
	}
	//4.ɾ������
	while (LinkList_Length(list)>0)
	{
		Teacher* tmp=(Teacher*)LinkList_Delete(list, 0);
		if (tmp == NULL)
		{
			return;
		}
		printf("tmp->age:%d \n", tmp->age);
	}

	//5.������Ա�
	LinkList_Clear(list);

	//6.�������Ա�
	LinkList_Destroy(list);

	system("pause");
	return 0;
}