#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"

int main()
{
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if (stack == NULL)
	{
		return;
	}
	int a[10];
	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack,&a[i]);
	}
	
	printf("Capacity:%d\n", SeqStack_Capacity(stack));
	printf("Length:%d\n", SeqStack_Size(stack));
	printf("Top:%d\n", SeqStack_Top(stack));

	while (SeqStack_Size(stack) > 0)
	{
		int tmp = SeqStack_Pop(stack);
		printf("Pop:%d\n", tmp);
	}

	system("pause");
	return 0;
}