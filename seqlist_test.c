#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"seqlist.h"

typedef struct _Teacher
{
	int age;
	char name[64];
}Teacher;

int main()
{
	int ret = 0;
	SeqList* list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 22;
	t2.age = 24;
	t3.age = 34;
	t4.age = 29;
	t5.age = 27;

	list = SeqList_Create(10);
	if (list == NULL)
	{
		printf("func create() ret:%d\n", ret);
		return 0;
	}
	ret = SeqList_Insert(list, (SeqListNode*)&t1, 0);//ͷ�巨
	ret = SeqList_Insert(list, (SeqListNode*)&t2, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t3, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t4, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t5, 0);

	for (int i = 0; i < SeqList_Length(list); i++)
	{
		Teacher* tmp = (Teacher*)SeqList_Get(list, i);
		if (tmp = NULL)
		{
			return 0;
		}
		printf("tmp->age:%d", tmp->age);
	}

	system("pause");
	return 0;
}