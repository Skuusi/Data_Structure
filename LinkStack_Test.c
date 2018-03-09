#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

typedef struct Teacher
{
	LinkStackNode node;
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

	//创建栈
	Stack* stack = NULL;
	stack = Stack_Create();
	if (stack == NULL)
	{
		printf("func Stack_Create err:-1!\n");
	}
	//入栈
	Stack_Push(stack, &t1);
	Stack_Push(stack, &t2);
	Stack_Push(stack, &t3);
	Stack_Push(stack, &t4);
	Stack_Push(stack, &t5);
	//出栈
	Teacher* tmp = (Teacher*)Stack_Pop(stack);
	printf("Stack_Pop:%d\n", tmp->age);
	printf("Stack_Pop:%d\n", ((Teacher*)Stack_Pop(stack))->age);

	printf("Stack_Size:%d\n", Stack_Size(stack));
	printf("Stack_Top:%d\n", ((Teacher*)Stack_Top(stack))->age);

	Stack_Destroy(stack);
	system("pause");
	return 0;
}