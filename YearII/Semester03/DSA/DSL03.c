#include "stdio.h"
#include "stdlib.h"
#define max_size 5
int stack[max_size], top = -1, i, status = 0, count = 0, item;
void push();
void pop();
void display();
void palin();
int main()
{
	int choice;
	while (1)
	{
		printf("\n\n \t\tSTACK OPERATIONS\n");
		printf("\n\t\t1.PUSH\n\t\t2.POP\n\t\t3.PALINDROME\n\t\t4.DISPLAY\n\t\t5.EXIT\n");
		printf("enter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			display();
			break;
		case 2:
			pop();
			display();
			break;
		case 3:
			palin();
			break;
		case 4:
			display();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\t\tInvalid choice\n");
			break;
		}
	}
	return 0;
}
void push()
{
	int item;
	if (top == (max_size - 1))
	{
		printf("\n \t\tSTACK OVERFLOW\n");
	}
	else
	{
		printf("\t\tEnter the element to be inserted\n");
		scanf("%d", &item);
		stack[++top] = item;
		count++;
	}
}
void pop()
{
	if (top == -1)
	{
		printf("\n \t\tSTACK UNDERFLOW\n");
	}
	else
	{
		item = stack[top];
		printf("\n\n\t\tthe popped element is:%d\t", stack[top]);
		top--;
		count--;
	}
}
void palin()
{
	int temp;
	for (i = 0, temp = count - 1; i < count, temp >= 0; i++, temp--)
	{
		if (stack[i] == stack[temp])
		{
			status++;
		}
	}
	if (status >= count)
		printf("\t\tStack is a palindrome\n");
	else
		printf("\t\tStack is not A Palindrome");
}
void display()
{
	int i;
	if (top == -1)
	{
		printf("NO elements in the stack\n");
	}
	else
	{
		printf("the stack elements are\n");
		for (i = top; i >= 0; i--)
		{
			printf("%d\n", stack[i]);
		}
	}
}
