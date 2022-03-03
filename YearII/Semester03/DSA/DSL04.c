#include <stdio.h> #include<stdlib.h> #include<string.h>
int f(char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 4;
	case '^':
	case '$':
		return 5;
	case '(':
		return 0;
	case '#':
		return -1;
	default:
		return 8;
	}
}
int g(char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 3;
	case '^':
	case '$':
		return 6;
	case '(':
		return 9;
	case ')':
		return 0;
	default:
		return 7;
	}
}
void infix_postfix(char infix[], char postfix[])
{
	int i, j, top;
	char symbol, s[30];
	top = -1;
	j = 0;
	s[++top] = '#';
	for (i = 0; i < strlen(infix); i++)
	{
		symbol = infix[i];
		while (f(s[top]) > g(symbol))
		{
			postfix[j] = s[top--];
			j++;
		}
		if (f(s[top]) != g(symbol))
		{
			s[++top] = symbol;
		}
		else
		{
			top--;
		}
	}
	while (s[top] != '#')
	{
		postfix[j++] = s[top--];
	}
	postfix[j] = '\0';
}
int main()
{
	char infix[50], postfix[50];
	printf("enter the valid infix exp\n");
	scanf("%s", infix);
	infix_postfix(infix, postfix);
	printf("the postfix exp\n");
	printf("%s\n", postfix);
	return 0;
}