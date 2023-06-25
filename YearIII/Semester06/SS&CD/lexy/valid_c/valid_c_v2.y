%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

int keywords = 0;
int digits = 0;
int operators = 0;
int identifiers = 0;

%}

%token KEYWORD DIGIT OPERATOR IDENTIFIER

%%
input:
    /* Empty production */
    | input token
    ;

token:
    KEYWORD {
        printf("Keyword: %s\n", $1);
        keywords++;
    }
    | DIGIT {
        printf("Digit: %d\n", $1);
        digits++;
    }
    | OPERATOR {
        printf("Operator: %s\n", $1);
        operators++;
    }
    | IDENTIFIER {
        printf("Identifier: %s\n", $1);
        identifiers++;
    }
    ;

%%

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("File not found\n");
        return 1;
    }

    yyin = fp;
    yyparse();

    printf("Keywords: %d\n", keywords);
    printf("Digits: %d\n", digits);
    printf("Operators: %d\n", operators);
    printf("Identifiers: %d\n", identifiers);

    return 0;
}

int yyerror(const char* s) {
    printf("Error: %s\n", s);
    return 0;
}