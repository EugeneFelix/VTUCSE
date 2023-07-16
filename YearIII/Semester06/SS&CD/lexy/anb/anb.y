%{
  #include<stdio.h>
  #include<stdlib.h>
  extern int yylex();
  extern int yyerror(const char* msg);
  extern char* yytext;
%}

%token A B

%%
input: s'\n' { printf("Valid string\n"); exit(0); }
s: A S B
S: ; | A S
%%

int main() {
	printf("%s\n", yytext);
	yyparse();
}

int yyerror(const char* msg) {
	printf("ERRORMSG: %s\n", msg);
	printf("Invalid string\n");
	exit(0);
}
