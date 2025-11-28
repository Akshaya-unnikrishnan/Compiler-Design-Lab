//YACC PROGRAM TO RECOGNIZE A VALID ARITHMETIC EXPRESSION USING YACC
 
%{ 
#include<stdio.h> 
#include<stdlib.h> 
int yylex(); 
%} 
%token NUMBER ID 
%left'+''-' 
%left'*''/' 
%% 
exp:exp'+'exp|exp'-'exp|exp'/'exp|'('exp')'|NUMBER|ID 
%% 
int main(int argc,char*argv[]){ 
printf("Enter the expression:"); 
yyparse(); 
printf("\n Valid Expression"); 
return 0; 
} 
int yyerror(){ 
printf("\n Invalid Expression"); 
exit(1); 
} 
int yywrap(){ 
return 1; 
} 
