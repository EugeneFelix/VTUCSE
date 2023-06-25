%{
#include <stdio.h>
#include "y.tab.h"
%}

%%

"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" { yylval.sval = strdup(yytext); return KEYWORD; }
[0-9]+ { yylval.ival = atoi(yytext); return DIGIT; }
[+\-*/] { return OPERATOR; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return IDENTIFIER; }
. { /* Ignore unrecognized characters */ }

%%