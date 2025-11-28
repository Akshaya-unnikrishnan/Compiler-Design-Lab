//LEX PROGRAM TO RECOGNIZE A VALID ARITHMETIC EXPRESSION USING YACC

%{ 
#include"y.tab.h" 
%} 
%% 
[0-9]+ {return NUMBER;} 
[a-zA-Z][a-zA-Z0-9]* {return ID;} 
\n {return 0;} 
. {return yytext[0];} 
%%
