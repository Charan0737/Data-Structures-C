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
	printf("enter the data to store in node:\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}
struct node *AddAtBeginning(struct node *head)
{
	struct node *newnode;
	newnode=createnode();
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	return head;
}
struct node *AddAtEnding(struct node *head)
{
	struct node *temp,*newnode;
	newnode=createnode();
	temp=head;
	if(head==NULL)
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
		printf("the linked list is empty\n");
	}
	else
	{
	  while(temp->next!=NULL)
	 {
		printf("%d\n",temp->data);
		temp=temp->next;
	 }
	   printf("%d\n",temp->data);
   }
}
/*int Length(struct node *head)
{
	struct node *temp;
	int c=0;
	temp=head;
	if(temp==NULL)
	{
		printf("the linked list is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			c++;
			temp=temp->next;
		}
	}
	return c;
}*/
struct node *DeleteAtBeginning(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	printf("the list is empty to delete\n");
	else
	{
		if(temp->next==NULL)
		{
		 head=NULL;
		 free(temp);
	    }
	    else
	    {
			head=temp->next;
		    free(temp);
		}
	}
	return head;
}
struct node *DeletionAtEnding(struct node *head)
{
	struct node *temp,*prev;
	temp=head;
	prev=NULL;
	
	if(temp==NULL)
	printf("the list is empty to delete\n");
	else
	{
		if(temp->next==NULL)
		{
			head=NULL;
			free(temp);
		}
		else
		{
			while(temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=NULL;
			free(temp);
		}
	}
	return head;
}
struct node *AddNode(struct node *head, int key)
{
	struct node *temp,*newnode;
	newnode=createnode();
	temp=head;
	
	if(temp==NULL)
	{
		printf("list is empty");
	}
	else
	{
		while(temp->next!=NULL && temp->data!=key)
		{
			temp=temp->next;
		}
		if(temp->data==key)
		{
			newnode->next=temp->next;
			temp->next=newnode;
		}
		else
		{
			printf("node not found\n");
			free(newnode);
		}
	}
	return head;
}	
struct node *DeleteNode(struct node *head,int keyy)
{
	struct node *temp,*prev;
	temp=head;
	prev=NULL;
	if(temp==NULL)
	{
		printf("the list is empty deletion can't be possible\n");
	}
	
	if(temp->data==keyy)
	{
		head=temp->next;
		free(temp);
	}
	else
	{
		while(temp->next!=NULL && temp->data!=keyy)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp->data==keyy)
		{
			prev->next=temp->next;
			free(temp);
		}
		else
		{
			printf("node not found\n");
		}
	}
	return head;
}
struct node *reverse(struct node *head)
{
	struct node *current,*temp,*next,*prev;
	current=head;
	next=prev=NULL;
	
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	temp=head;
	
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
	
	
	
	return head;
}
int main()
{
	int v,key,keyy;
	while(1)
	{
		printf("1.AddatBeginning 2.AddAtEnding 3.AddNode 4.Traverse 5.DeletionAtBeginning 6.DeletionAtEnding 7.DeleteNode 8.Reverse 9.stop \n");
		printf("choose any option: \n");
		scanf("%d",&v);
		
		switch(v)
		{
			case 1:
			head=AddAtBeginning(head);
			break;
			case 2:
			head=AddAtEnding(head);
			break;
			case 3:
			printf("enter the key\n");
			scanf("%d",&key);
			head=AddNode(head,key);
			break;
			case 4:
			Traverse();
			break;
			case 5:
			head=DeleteAtBeginning(head);
			break;
			case 6:
			head=DeletionAtEnding(head);
			break;
			case 7:
			printf("enter the node which you want to delete: ");
			scanf("%d",&keyy);
			head=DeleteNode(head,keyy);
			break;
			case 8:
			head=reverse(head);
			break;
			case 9:
			exit(0);
			default:
			printf("input not available\n");
		}
	}
}
