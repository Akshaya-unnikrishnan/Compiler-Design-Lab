//YACC PROGRAM TO RECOGNIZE A VALID IDENTIFIER
 
%{ 
#include<stdio.h> 
#include<stdlib.h> 
int yylex(); 
%} 
%token DIGIT ALPHA 
%% 
var:ALPHA|var ALPHA|var DIGIT; 
%% 
int main(int argc,char*argv[]){ 
printf("Enter a variable name:"); 
yyparse(); 
printf("\n Valid Variable"); 
return 0; 
} 
int yyerror(){ 
printf("\n Invalid Variable"); 
exit(1); 
} 
int yywrap(){ 
return 1; 
} 
