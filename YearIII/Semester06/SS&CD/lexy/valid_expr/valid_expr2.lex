%option noyywrap
%{
#include<stdio.h>
int v = 0, op = 0, id = 0, flag = 0;
%}

DIGIT [0-9]
OPS [\+\-\*\/\=]

%%
{DIGIT}{DIGIT}* { id++; printf("\nIdentifier:"); ECHO;}
{OPS} { op++; printf("\nOperartor:"); ECHO;}
"(" { v++; }
")" { v--; }
";" { flag = 1; }
.|\n { return 0; }
%%

int main(int argc, char* argv[]){
	printf("Enter the expression:\n");
	yylex();
	if((op+1) == id && v == 0 && flag == 0) {
		printf("\n\nIdentifiers count is: %d\nOperators count is: %d\n",id,op);
		printf("\nExpression is Valid\n");
	}
	else
		printf("\nExpression is Invalid\n");
	return 0;
}
