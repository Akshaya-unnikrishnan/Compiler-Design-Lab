//YACC PROGRAM IMPLEMENTATION OF CALCULATOR USING LEX AND YACC

%{ 
#include<stdio.h> 
int yylex(); 
int flag=0; 
%} 
%token NUMBER 
%left '+''-' 
%left '*''/''%' 
%left '('')' 
%% 
ArithmeticExpression:E{ 
printf("\nResult=%d\n",$$); 
return 0; 
}; 
E:E'+'E{$$=$1+$3;} 
|E'-'E{$$=$1-$3;} 
|E'*'E{$$=$1*$3;} 
|E'/'E{$$=$1/$3;} 
|E'%'E{$$=$1%$3;} 
|'('E')'{$$=$2;} 
|NUMBER{$$=$1;} 
; 
%% 
void main(){ 
printf("\nEnter Any Arithmetic Expression whichy can have operations 
Addition,Subtraction,Multiplication,Division,Modules & Round brackets:\n"); 
yyparse(); 
if (flag==0) 
printf("\nEntered Arithmetic Expression is Valid \n"); 
} 
void yyerror(){ 
printf("\nEntered Arithmetic Expression is Invalid \n"); 
flag=1; } 
