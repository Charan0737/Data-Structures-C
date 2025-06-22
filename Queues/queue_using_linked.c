#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *createNode()
{
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	printf ("Enter data:");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	return newNode;
}
void printindex()
{
	printf("Menu:\n");
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.IsEmpty\n");
	printf("4.Display\n");
	printf("5.Exit\n");
	printf("6.Show Index\n");
}
void enqueue()
{
	struct node *newNode;
	newNode=createNode();
	if(front==NULL)
	{
		front=rear=newNode;
	}
	else
	{
		rear->next=newNode;
		rear=newNode;
	}
}
void dequeue()
{
	int item;
	struct node *temp=front;
	if(front==NULL)
	{
		printf("Queue underflows\n");
	}
	else
	{
		item=temp->data;
		front=front->next;
		free(temp);
		printf("The dequeued element is %d\n",item);
	}
}
void isEmpty()
{
	if(front==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue is not empty\n");
	}
}
void display()
{
	struct node *p=front;
	if(front==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
	}
	printf("\n");
}
int main()
{
	int ch;
	printindex();
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				isEmpty();
				break;
			case 4:
				display();
				break;
			case 5:
				return 0;
				break;
			case 6:
				printindex();
				break;
			default:
				printf("Wrong Choice\n");
		}
	}
}
