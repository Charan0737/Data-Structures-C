#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *createnode()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}
struct node *AddNode(struct node *head)
{
	struct node *newnode,*temp;
	newnode=createnode();
	temp=head;
	if(temp==NULL)
	{
		head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	return head;
}
void Traverse()
{
	struct node *temp;
	temp=head;
	
	if(temp==NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
struct node *Duplicate(struct node *head)
{
	struct node *temp,*prev,*current;
	prev=current=NULL;
	temp=head;
	
	if(temp==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			prev=temp;
			current=temp->next;
			while(current!=NULL)
			{
				if(temp->data==current->data)
				{
					prev->next=current->next;
					free(current);
					current=prev->next;
				}
				else
				{
					prev=current;
					current=current->next;
				}
			}
			temp=temp->next;
		}
	}
	return head;
}
int main()
{
	int v;
	while(1)
	{
		printf("1.AddNode  2.Traverse  3.Duplicate  4.stop\n");
		printf("choose any option\n");
		scanf("%d",&v);
		switch(v)
		{
			case 1:
			head=AddNode(head);
			break;
			case 2:
			Traverse();
			break;
			case 3:
			head=Duplicate(head);
			break;
			case 4:
			exit(0);
			break;
			default:
			printf("invalid input");
		}
	}
}
