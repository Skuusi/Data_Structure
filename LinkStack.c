#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

typedef struct _tag_LinkStack
{
	LinkStackNode header;
	int length;
}TLinkStack;

Stack* Stack_Create()
{
	TLinkStack* tstack = NULL;
	tstack = (TLinkStack*)malloc(sizeof(TLinkStack));
	memset(tstack, 0, sizeof(TLinkStack));
	tstack->length = 0;
	tstack->header.next = NULL;
	return tstack;
}

void Stack_Destroy(Stack* stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}

void Stack_Clear(Stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	TLinkStack* tstack = NULL;
	tstack = (TLinkStack*)stack;
	tstack->length = 0;
	tstack->header.next = NULL;
}

int Stack_Push(Stack* stack, LinkStackNode* item)
{
	if (stack == NULL || item == NULL)
	{
		printf("Stack_Push err:-1!\n");
		return;
	}
	TLinkStack* tstack = NULL;
	tstack = (TLinkStack*)stack;
	item->next = tstack->header.next;
	tstack->header.next = item;
	tstack->length++;
	return 0;
}

void* Stack_Pop(Stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	TLinkStack* tstack = NULL;
	tstack = (TLinkStack*)stack;
	LinkStackNode* tmp = tstack->header.next;
	tstack->header.next = tmp->next;
	return tmp;
}

void* Stack_Top(Stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	TLinkStack* tstack = NULL;
	tstack = (TLinkStack*)stack;
	return tstack->header.next;
}

int Stack_Size(Stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	TLinkStack* tstack = NULL;
	tstack = (TLinkStack*)stack;
	return tstack->length;
}
