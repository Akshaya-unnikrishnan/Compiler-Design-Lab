//IMPLEMENT INTERMEDIATE CODE GENERATION FOR SIMPLE EXPRESSIONS
 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<ctype.h> 
#define MAX 100 
typedef struct{ 
char op; 
char arg1[10],arg2[10],res[10]; 
int isOptimized; 
char optimizedValue[10]; 
}Expression; 
int n; 
//Function to check if a string is a number(constant) 
int isConstant(char*s){ 
for(int i=0;s[i];i++){ 
if(!isdigit(s[i])) 
return 0; 
} 
return 1; 
} 
//function to convert int to string 
void intToStr(int val,char str[]){ 
sprintf(str,"%d",val); 
} 
//function to evaluate the expression   
int evaluate(char op,int a,int b){ 
switch(op){ 
case'+':return a+b; 
case'-':return a-b; 
case'*':return a*b; 
case'/':return b!=0?a/b:0; 
case'=':return a; 
default:return 0; 
}} 
int main(){ 
Expression expr[MAX]; 
printf("Enter number of expressions:"); 
scanf("%d",&n); 
//input expression 
for(int i=0;i<n;i++){ 
printf("Enter expression %d(format:operand1 operator operand2 result):",i+1); 
scanf("%s %c %s %s",expr[i].arg1,&expr[i].op,expr[i].arg2,expr[i].res); 
expr[i].isOptimized=0; 
expr[i].optimizedValue[0]='\0'; 
} 
//constant folding & propagation 
for(int i=0;i<n;i++){ 
//case:both operands are constants or assignment with constant 
if((isConstant(expr[i].arg1)&&isConstant(expr[i].arg2))|| 
(expr[i].op=='='&&isConstant(expr[i].arg1))){ 
int a=atoi(expr[i].arg1); 
int b=(expr[i].op=='=')?0:atoi(expr[i].arg2); 
int res=evaluate(expr[i].op,a,b); 
char resStr[10]; 
intToStr(res,resStr); 
//mark expression as optimized 
expr[i].isOptimized=1; 
strcpy(expr[i].optimizedValue,resStr); 
//propagated value to future expressions 
for(int j=i+1;j<n;j++){ 
if(strcmp(expr[i].res,expr[j].arg1)==0) 
strcpy(expr[j].arg1,resStr); 
if(strcmp(expr[i].res,expr[j].arg2)==0) 
strcpy(expr[j].arg2,resStr); 
}}} 
//print optimized expressions 
printf("\nOptimized Expressions:\n"); 
for(int i=0;i<n;i++){ 
if(expr[i].isOptimized) 
printf("%s%c%s->%s=%s\n",expr[i].arg1,expr[i].op,expr[i].arg2,expr[i].res, 
expr[i].optimizedValue); 
else 
printf("%s%c%s->%s\n",expr[i].arg1,expr[i].op,expr[i].arg2,expr[i].res); 
} 
return 0; 
} 
