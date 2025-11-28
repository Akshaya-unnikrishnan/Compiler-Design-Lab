//CONSTANT PROPAGATION
 
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
void push(char); 
char pop(); 
void code_gen(); 
void in_to_pos(); 
int get_pre(char); 
int top = 0, no = 1; 
char stack[30], inf[50], post[50], str[10]; 
void main(){ 
char ch; 
int i = 0; 
inf[i++] = '('; 
printf("\nEnter the arithmetic expression (infix):\n"); 
scanf("%c", &ch); 
while (ch != '\n'){ 
inf[i++] = ch; 
scanf("%c", &ch); 
} 
inf[i++] = ')'; 
inf[i] = '\0'; 
in_to_pos(); 
printf("Postfix form: "); 
puts(post); 
code_gen(); 
} 
//---------------- Infix to Postfix Conversion ----------------// 
void in_to_pos(){ 
int i, j = 0; 
char ch; 
for (i = 0; inf[i] != '\0'; i++){ 
ch = inf[i]; 
if (isalnum(ch))         
post[j++] = ch;         
else if (ch == '(')         
push(ch); 
else if (ch == ')'){ 
while (stack[top] != '(') 
post[j++] = pop(); 
pop(); 
} 
else{ 
while (get_pre(stack[top]) >= get_pre(ch)) 
post[j++] = pop(); 
push(ch); 
}} 
post[j] = '\0'; 
} 
//---------------- Code Generation ----------------// 
void code_gen(){ 
int i = 0; 
char temp_op1, temp_op2; 
while (post[i] != '\0'){ 
if (post[i] == '*' || post[i] == '+' || post[i] == '-' || post[i] == '/' || post[i] == '^'){ 
if (post[i] == '*') 
printf("mul("); 
else if (post[i] == '^') 
printf("pow("); 
else if (post[i] == '+') 
printf("add("); 
else if (post[i] == '-') 
printf("sub("); 
else if (post[i] == '/') 
printf("div("); 
temp_op1 = pop(); 
temp_op2 = pop(); 
printf("%c,%c)->t%d\n", temp_op2, temp_op1, no); 
sprintf(str, "t%d", no); 
push(str[0]); 
no++; 
} 
else 
push(post[i]); 
i++; 
}} 
//---------------- Precedence Function ----------------// 
int get_pre(char chr){ 
switch (chr){ 
case '(': return 0; 
case '+': 
case '-': return 1; 
case '*': 
case '/': return 2; 
case '^': return 3; 
default : return 999; 
}} 
//---------------- Stack Operations ----------------// 
void push(char c){ 
stack[++top] = c; 
} 
char pop(){ 
return (stack[top--]); 
} 
