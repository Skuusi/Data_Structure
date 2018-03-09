#ifndef __LINKSTACK__
#define __LINKSTACK__

typedef void Stack;

typedef struct _tag_LinkStackNode
{
	struct _tag_LinkStackNode* next;
}LinkStackNode;

LinkStackNode node;

Stack* Stack_Create();

void Stack_Destroy(Stack* stack);

void Stack_Clear(Stack* stack);

int Stack_Push(Stack* stack, LinkStackNode* item);

void* Stack_Pop(Stack* stack);

void* Stack_Top(Stack* stack);

int Stack_Size(Stack* stack);

#endif // !__LINKSTACK__

