#include<stdio.h>
#include<math.h>
#include<ctype.h>
int stack[50], operand1, operand2, top=-1;
void push(int element)
{
top = top + 1;
stack[top] = element;
}
int pop()
{
return stack[top--];
}
int main()
{
char postfix[50];
int result, i;
printf("Enter Postfix Expression: ");
scanf("%[^\n]%*c",postfix);
for(i=0; postfix[i]!='\0'; i++)
{
if((postfix[i])==' ')
continue; 
else if(isdigit(postfix[i]))
{
int num=0;
while(isdigit(postfix[i]))
{
num = num * 10 + (postfix[i] - 48);
i++;
}
push(num);
}
else
{
operand2=pop();
operand1=pop();
switch(postfix[i])
{
case '+': result=operand1+operand2;
push(result);
break;
case '-': result=operand1-operand2;
push(result);
break;
case '*': result=operand1*operand2;
push(result);
break;
case '/': result=operand1/operand2;
push(result);
break;
case '^': result= pow(operand1, operand2);
push(result);
break;
}
}
}
printf("The Result is %d", pop());
return 0;
}
