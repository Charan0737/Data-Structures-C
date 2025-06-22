//took head as top dont confuse future charan
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void pop()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("stack underflows\n");
	}
	else
	{
		printf("the poped item is %d\n",top->data);
		top=temp->next;	
		free(temp);
	}
}	
void peek()
{
	if(top==NULL)
	{
		printf("stack underflows\n");
	}
	else
	{
		printf("%d\n",top->data);
	}
}
void display()
{
	struct node *temp;
	temp=top;
	
	if(temp==NULL)
	{
		printf("stack underflows\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void isempty()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("stack is not empty\n");
	}
}
void menu()
{
	printf("\n1.push  2.pop  3.peek  4.display  5.isempty  6.exit  7.menu\n");
}
int main()
{
	int v,data;
	menu();
	while(1)
	{
		printf("\nchoose any option: ");
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
			isempty();
			break;
			case 6:
			exit(1);
			break;
			case 7:
			menu();
			break;
			default:
			printf("invalid input");
		}
	}
}
	
	
	
		
	
	
		
	
	
	
	

	
