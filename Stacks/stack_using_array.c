#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;
void push(int data)
{
	if(top==max-1)
	{
		printf("the stack is full, push operation cant be done\n");
	}
	else
	{
		top++;
		stack[top]=data;
		printf("the data %d is pushed\n",data);
	}
}
void pop()
{
	int deleted;
	if(top==-1)
	{
		printf("the stack is empty\n");
	}
	else
	{
		deleted=stack[top];
		top--;
		printf("the value %d is popped\n",deleted);
	}
}
void peek()
{
	if(top==-1)
	{
		printf("the stack is empty\n");
	}
	else
	{
		printf("%d\n",stack[top]);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("the stack is empty\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
void isfull()
{
	if(top==max-1)
	{
		printf("the stack is full\n");
	}
	else
	{
		printf("the stack is not full\n");
	}
}
void isempty()
{
	if(top==-1)
	{
		printf("the stack is empty\n");
	}
	else
	{
		printf("the stack is not empty\n");
	}
}
void menu()
{
	printf("1.push  2.pop  3.peek  4.display  5.isfull  6.isempty  7.exit  8.menu\n");
}
int main()
{
	int v,data;
	menu();
	
	while(1)
	{
		printf("choose any option: \n");
		scanf("%d",&v);
		
		switch(v)
		{
			case 1:
			printf("enter the data: ");
			scanf("%d",&data);
			push(data);
			break;
			case 2: 
			pop();
			break;
			case 3:
			peek();
			break;
			case 4:
			display();
			break;
			case 5:
			isfull();
			break;
			case 6:
			isempty();
			break;
			case 7:
			exit(1);
			break;
			case 8:
			menu();
			break;
			default:
			printf("invalid input");
		}
	}
}
