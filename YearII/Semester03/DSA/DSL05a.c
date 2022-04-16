#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
double compute(char symbol, double op1, double op2)
{
	switch (symbol)
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	case '$':
	case '^':
		return pow(op1, op2);
	default:
		return 0;
	}
}
int main()
{
	double s[20], res, op1, op2;
	int top = -1, i;
	char postfix[20], symbol;
	printf("Enter the postfix expression : \n");
	gets(postfix);
	for (i = 0; i < strlen(postfix); i++)
	{
		symbol = postfix[i];
		if (isdigit(symbol))
		{
			s[++top] = symbol - '0';
		}
		else
		{
			op2 = s[top--];
			op1 = s[top--];
			res = compute(symbol, op1, op2);
			s[++top] = res;
		}
	}
	res = s[top--];
	printf("\n The result is : %0.3f\n", res);
	return 0;
}