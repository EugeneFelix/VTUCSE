%option noyywrap

%{
 #include "y.tab.h"
%}

%%
a {return A;}
b {return B;}
[_c-zC-Z] {return 0;}
[\n] {return '\n';}
%%
