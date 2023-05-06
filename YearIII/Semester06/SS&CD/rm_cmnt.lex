 %option noyywrap
%{

%}

%%
"/*"[a-zA-Z0-9' '\t\n]+"*/" {}
"//".* {}
%%

int main()
{
 yyin = fopen("in.c","r");
 yyout = fopen("out.c","w");
 yylex();
 fclose(yyin);
 fclose(yyout);
 return 0;
}
