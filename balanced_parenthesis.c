#include<stdio.h>
#include<string.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char ch) 
{
if(top==SIZE-1)
printf("Stack is Full(Overflow).\n");
else 
 stack[++top]= ch;
}
char pop() 
{
if(top==-1) 
{
 printf("Stack is Empty(Underflow).\n");
 return '\0';
}
return stack[top--];
}
int isMatchingPair(char a, char b) 
{
if((a=='(' && b==')')||(a=='[' && b==']')||( a=='{' && b=='}'))
return 1;
else
 return 0;
}
int isBalancedPair(char exp[]) 
{
int i;
for(i=0; exp[i]!='\0'; i++) 
{
char ch=exp[i];
if(ch=='(' || ch=='[' || ch=='{')
{
 push(ch);
 } 
else if(ch==')' || ch==']' || ch=='}') 
{
 if(top==-1 || !isMatchingPair(pop(), ch)) 
{
 return 0; 
 }
 }
}
if(top==-1) 
{
 return 1;
}
return 0;
}
int main() 
{
char exp[SIZE];
printf("Enter Expression: ");
scanf("%[^\n]s", exp);
if(strlen(exp)>=SIZE)
{
 printf("Input exceeds the allowed size of %d characters!\n", SIZE-1);
 return 1;
}
if(isBalancedPair(exp))
printf("The Given Expression is Balanced.\n");
else 
 printf("The Given Expression is Not Balanced.\n");
}
