%{
  #include "y.tab.h"
  #include <math.h>
%}

%%
[0-9]+ { yylval = atoi(yytext); return NUM; }
[+] { return '+'; }
[-] { return '-'; }
[*] { return '*'; }
[/] { return '/'; }
[\t ]+ ;
[\n] { return 0; }
. { return yytext[0]; }
%%
