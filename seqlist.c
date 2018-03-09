#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"seqlist.h"

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int* node;//数组动态分配内存
}TSeqList;

SeqList * SeqList_Create(int capacity)
{
	int ret = 0;
	TSeqList* tmp = NULL;
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func create() err:%d\n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));

	//根据capacity的大小分配节点空间
	tmp->node = (unsigned int*)malloc(sizeof(unsigned int*)*capacity);
	if (tmp->node == NULL)
	{
		ret = -2;
		printf("func create() err:malloc err %d \n", ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

void SeqList_Destroy(SeqList * list)
{
	TSeqList* tlist = NULL;
	if (list == NULL)
	{
		return ;
	}
	tlist = (TSeqList*)list;
	if (tlist->node != NULL)
	{
		free(tlist->node);
	}
	free(tlist);
}

void SeqList_Clear(SeqList * list)
{
	TSeqList* tlist = NULL;
	if (list == NULL)
	{
		return ;
	}
	tlist = (TSeqList*)list;
	tlist->length = 0;
}

int SeqList_Length(SeqList * list)
{
	TSeqList* tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->length;
}

int SeqList_Capacity(SeqList * list)
{
	TSeqList* tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->capacity;
}

int SeqList_Insert(SeqList * list, SeqListNode * node, int pos)
{
	int ret = 0;
	TSeqList* tlist = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func insert() err:%d \n", ret);
		return ret;
	}
	tlist = (TSeqList*)list;
	//判断数组是不是满了
	if(tlist->length >= tlist->capacity)
	{
		ret = -2;
		printf("func insert() err:%d \n", ret);
		return ret;
	}
	//容错修正
	if (pos > tlist->length && pos < tlist->capacity)
	{
		tlist->node[tlist->length + 1] = pos;
		tlist->length++;
		return 0;
	}
	//1.元素后移
	for (int i = tlist->length; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i - 1];
	}
	//2.插入元素
	tlist->node[pos] = (unsigned int)node;
	tlist->length++;
	return 0;
}

SeqListNode * SeqList_Get(SeqList * list, int pos)
{
	int ret = 0;
	TSeqList* tlist = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func insert() err:%d \n", ret);
		return NULL;
	}
	tlist = (TSeqList*)list;
	return tlist->node[pos];
}

SeqListNode * SeqList_Del(SeqList * list, int pos)
{
	int ret = 0;
	TSeqList* tlist = NULL;
	if (list == NULL  || pos < 0)
	{
		ret = -1;
		printf("func del() err:%d \n", ret);
		return NULL;
	}
	tlist = (TSeqList*)list;

	//1.删除元素
	ret =tlist->node[pos];
	//2.元素前移
	for (int i=pos+1; i < tlist->length; i++)
	{
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;
	return NULL;
}
