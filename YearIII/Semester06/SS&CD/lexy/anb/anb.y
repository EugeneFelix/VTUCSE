%{
  #include<stdio.h>
  #include<stdlib.h>
  extern int yylex();
  extern int yyerror();
%}

%token A B

%%
input: s'\n' { printf("Valid string\n"); exit(0); }
s: A s1 B
s1: ; | A s1
%%

int main() {
  printf("Enter a string\n");
  yyparse();
}

int yyerror() {
 printf("Invalid string\n");
 exit(0);
}
