//lex program to display number of lines,words,characters
%{ 
#include<stdio.h> 
int cc=0; 
int wc=0; 
int lc=0; 
%} 
%% 
[\n] {lc++;cc++;} 
[\t]+ {cc+=yyleng;} 
[^\t\n]+ {wc++;cc+=yyleng;} 
. {cc++;} 
%% 
int main(){ 
printf("Enter text:\n"); 
yylex(); 
printf("\nTotal lines:%d\n",lc); 
printf("Total words:%d\n",wc); 
printf("Total characters:%d\n",cc); 
return 0; 
} 
int yywrap(){ 
return 1; 
}
