#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int stack[max_size], top = -1, i, status = 0, count = 0, item;
void push();
void pop();
void display();
void palin();
int main()
{
	int choice;
	while (choice)
	{
		printf("\n\n STACK OPERATIONS\n");
		printf("\n1.PUSH\n2.POP\n3.PALINDROME\n4.DISPLAY\n5.EXIT\n");
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
			printf("invalid choice\n");
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
		printf("\n STACK OVERFLOW\n");
	}
	else
	{
		printf("enter the element to be inserted\n");
		scanf("%d", &item);
		top = top + 1;
		stack[top] = item;
		count++;
	}
}
void pop()
{
	if (top == -1)
	{
		printf("\n STACK UNDERFLOW\n");
	}
	else
	{
		item = stack[top];
		printf("\n\nthe popped element is:%d\t", stack[top]);
		top = top - 1;
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
		printf("A palindrome\n");
	else
		printf("Not A Palindrome");
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