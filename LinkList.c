#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LinkList.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList * LinkList_Create()
{
	TLinkList* tlist = NULL;
	tlist = (TLinkList*)malloc(sizeof(TLinkList));
	memset(tlist, 0, sizeof(TLinkList));
	tlist->length = 0;
	tlist->header.next = NULL;
	return tlist;
}

void LinkList_Destroy(LinkList * list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}

void LinkList_Clear(LinkList * list)
{
	TLinkList* tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TLinkList*)list;
	tlist->length = 0;
	tlist->header.next = NULL;
}

int LinkList_Length(LinkList * list)
{
	TLinkList* tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TLinkList*)list;
	return tlist->length;
}

int LinkList_Insert(LinkList * list, LinkListNode * node, int pos)
{
	int ret = 0;
	LinkListNode* current = NULL;

	if (list == NULL || pos < 0 || node == NULL)
	{
		printf("func LinkList_Insert() err \n");
		return -1;
	}
	TLinkList* tlist = NULL;
	tlist = (TLinkList*)list;
	current = &(tlist->header);//

	for (int i = 0; i < pos&&(current->next!=NULL); i++)
	{
		//tlist->header = tlist->header.next;
		current = current->next;
	}
	//node->next = tlist->header.next;
	//tlist->header.next = node;
	node->next = current->next;
	current->next = node;
	tlist->length++;
	return 0;
}

LinkListNode * LinkList_Get(LinkList * list, int pos)
{
	int ret = 0;
	LinkListNode* current = NULL;

	if (list == NULL || pos < 0 )
	{
		printf("func LinkList_Insert() err \n");
		return NULL;
	}
	TLinkList* tlist = NULL;
	tlist = (TLinkList*)list;
	current = &(tlist->header);//

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		//tlist->header = tlist->header.next;
		current = current->next;
	}
	return current;
}

LinkListNode * LinkList_Delete(LinkList * list, int pos)
{
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;

	TLinkList* tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func LinkList_Delete err!\n");
		return NULL;
	}
	tlist = (TLinkList*)list;
	current = &(tlist->header);//让辅助指针变量指向链表的头部
	
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	ret = current->next;//缓存被删除节点位置
	current->next = ret->next;//连线
	tlist->length--;
	return NULL;
}
