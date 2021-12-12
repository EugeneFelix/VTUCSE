int stack[100], top = -1, flag = 1;
int i, temp, item, rev[100], num[100];

void push()
{
	if (top == (99))
	{
		printf("\t\t\nStack Overflow!");
	}
	else
	{
		printf("\tEnter the element to be inserted:\t");
		scanf("%d", &item);
		top = top + 1;
		stack[top] = item;
	}
	temp = top;
}
void pop()
{
	if (top == -1)
	{
		printf("\tStack Underflow!\nThe stack is empty!");
		flag = 0;
	}
	else
	{
		item = stack[top];
		top = top - 1;
		printf("\t\t\n%d was popped from the stack\n", item);
	}
}
void pali()
{
	i = 0;
	if (top == -1)
	{
		printf("\tPush some elements into the stack first\n");
	}
	else
	{
		while (top != -1)
		{
			rev[top] = stack[top];
			pop();
		}
		top = temp;
		for (i = 0; i <= temp; i++)
		{
			if (stack[top--] == rev[i])
			{
				if (i == temp)
				{
					printf("Palindrome\n");
					return;
				}
			}
		}
		printf("Not a Palindrome\n");
	}
}
void display()
{
	int i;
	top = temp;
	if (top == -1)
	{
		printf("\nStack is Empty:\n");
	}
	else
	{
		printf("\t\tThe stack elements are:\n");
		for (i = top; i >= 0; i--)
		{
			printf("\t\t%d\n", stack[i]);
		}
	}
}