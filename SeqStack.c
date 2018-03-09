#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"

typedef struct _tag_SeqStack
{
	int length;//实际大小
	int capacity;//容量
	unsigned int* node;//节点
}TSeqStack;

SeqStack * SeqStack_Create(int capacity)
{
	TSeqStack* tmp = NULL;
	tmp = (TSeqStack*)malloc(sizeof(TSeqStack));
	if (tmp == NULL)
	{
		printf("func SeqStack_Create err:1!\n");
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqStack));
	tmp->node = (unsigned int*)malloc(sizeof(unsigned int*)*capacity);
	if (tmp->node == NULL)
	{
		printf("func SeqStack_Create err:2!\n");
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

void SeqStack_Destroy(SeqStack* stack) 
{
	if (stack == NULL)
	{
		return;
	}
	TSeqStack* tstack = NULL;
	tstack = (TSeqStack*) stack;
	if (tstack->node != NULL)
	{
		free(tstack->node);
	}
	free(tstack);
}

void SeqStack_Clear(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	TSeqStack* tstack = NULL;
	tstack = (TSeqStack*)stack;
	tstack->length = 0;
}

int SeqStack_Push(SeqStack* stack, void* item)
{
	if (stack == NULL || item == NULL)
	{
		printf("func SeqStack_Push err:-1!\n");
		return -1;
	}
	TSeqStack* tstack = NULL;
	tstack = (TSeqStack*)stack;
	if (tstack->length >= tstack->capacity)
	{
		printf("func SeqStack_Push err:-2!\n");
		return -2;
	}
	for (int i = tstack->length; i >= 0; i--)
	{
		tstack->node[i] = tstack->node[i - 1];
	}
	tstack->node[0] = (unsigned int)item;
	tstack->length++;
	return 0;
}

void* SeqStack_Pop(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func SeqStack_Pop err:-1!\n");
		return;
	}
	TSeqStack* tstack = NULL;
	tstack = (TSeqStack*)stack;
	int tmp = tstack->node[0];
	for (int i = tstack->length; i >= 0; i--)
	{
		tstack->node[i - 1] = tstack->node[i];
	}
	return tmp;
}

void* SeqStack_Top(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("SeqStack_Top err:-1!\n");
		return;
	}
	TSeqStack* tstack = NULL;
	tstack = (TSeqStack*)stack;
	return tstack->node[0];
}

int SeqStack_Size(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	TSeqStack* tstack = NULL;
	tstack = (TSeqStack*)stack;
	return tstack->length;
}

int SeqStack_Capacity(SeqStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	TSeqStack* tstack = NULL;
	tstack = (TSeqStack*)stack;
	return tstack->capacity;
}
