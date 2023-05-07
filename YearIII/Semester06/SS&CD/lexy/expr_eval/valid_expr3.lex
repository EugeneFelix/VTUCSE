%{
#include<stdlib.h>
#include<stdio.h>
char opnd[10];
char oper[10];
int i=0,j=0,k,l;
void invalid();
%}
%x op od
%%
[a-zA-Z0-9] {opnd[i++]=yytext[0]; BEGIN op;}
<op>['+''*''/'] {oper[j++]=yytext[0]; BEGIN od;}
<op>"-" {oper[j++]=yytext[0]; BEGIN od;}
<op>\n {if(i==j+1) return 0; else invalid();}
<op>. invalid();
<od>[a-zA-Z0-9] {opnd[i++]=yytext[0]; BEGIN op;}
<od>. invalid();
. invalid();
\n return 0;
%%

void invalid()
{
	printf("Invalid Expression");
	exit(0);
}
int main()
{
	printf("Enter an arithmetic expression\n");
	yylex();
	printf("Valid Expression\n");
	printf("Number of operands present are %d\n",i);
    printf("Number of operators present are %d\n",j);
	if(i!=0)
	{
		printf("Operands in this valid expression are :\n");
		for(k=0;k<i;k++)
			printf("%c\n",opnd[k]);
	}
	if(j!=0)
	{
		printf("Operators in this valid expression are :\n");
		for(k=0;k<j;k++)
			printf("%c\n",oper[k]);
	}
	return 0;
}
