#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *createNode()
{
	struct node *newNode=(struct node*) malloc(sizeof(struct node));
	newNode->prev=NULL;
	printf("Enter data:");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	return newNode;
}
struct node *insertAtBegin(struct node *head)
{
	struct node *temp,*newNode;
	temp=head;
	newNode=createNode();
	if(temp==NULL)
	head=newNode;
	else
	{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
	return head;
}
struct node *insertAtEnd(struct node *head)
{
	struct node *temp,*newNode;
	temp=head;
	newNode=createNode();
	if(temp==NULL)
	{
		head=newNode;
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
		newNode->prev=temp;
	}
	return head;
}
struct node *insertAfter(struct node *head,int key)
{
	struct node *temp,*newNode;
	temp=head;
	newNode=createNode();
	if(temp==NULL)
	printf("Node not found\n");
	else
	{
		while(temp->next!=NULL && temp->data!=key)
		temp=temp->next;
		if(temp->data!=key)
		printf("Node not found.\n");
		else 
		{
			if(temp->next==NULL)
			{
				temp->next=newNode;
				newNode->prev=temp;
			}
			else
			{
				newNode->next=temp->next;
				newNode->prev=temp;
				(temp->next)->prev=newNode;
				temp->next=newNode;
			}
		}
	}
	return head;
}
struct node *deleteAtBegin(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	printf("List is empty. Deletion is not possible.\n");
	else if(temp->next==NULL)
	{
		head=NULL;
		free(temp);
	}
	else
	{
		head=temp->next;
		temp->next=NULL;
		head->prev=NULL;
		free(temp);
	}
	return head;
}
struct node *deleteAtEnd(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	printf("List is empty. Deletion is not possible.\n");
	else if(temp->next==NULL)
	{
		head=NULL;
		free(temp);
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		(temp->prev)->next=NULL;
		temp->prev=NULL;
		free(temp);
	}
	return head;
}
struct node *deleteANode(struct node *head,int key)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	printf("List is empty. Deletion is not possible.\n");
	else if(temp->next==NULL && temp->data==key)
	{
		head=NULL;
		free(temp);
	}
	else
	{
		while(temp->next!=NULL && temp->data!=key)
		temp=temp->next;
		if(temp->data==key)
		{
			if(temp->prev==NULL)
			head=temp->next;
			else
			(temp->prev)->next=temp->next;
			if(temp->next!=NULL)
			(temp->next)->prev=temp->prev;
			free(temp);
		}
		else
		printf("Node not found.\n");
	}
	return head;
	
}
void traverse(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	printf("List is empty.\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
struct node *reverse(struct node *head)
{
	struct node *t,*curr;
	curr=head;
	if(curr==NULL)
	printf("List is empty.\n");
	else if(curr->next==NULL)
	head=curr;
	else
	{
		while(curr!=NULL)
		{
			t=curr->prev;
			curr->prev=curr->next;
			curr->next=t;
			curr=curr->prev;
		}
		head=t->prev;
	}
	return head;
}
void length(struct node *head)
{
	int count=0;
	struct node *temp;
	temp=head;
	
	if(temp==NULL)
	{
		printf("the size is %d\n",count);
	}
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
	   printf("the length is: %d",count);
   }
}
int main()
{
	int ch,item;
	while(1)
	{
		printf("1.Display 2.Insert at beginning 3.Insert at ending 4.Insert after an item\n5.Delete at front 6.Delete at end 7.Delete a node 8.Reverse 9.length 10.Exit\n");
		printf("choose any option:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			traverse(head);
			break;
			case 2:
			head=insertAtBegin(head);
			break;
			case 3:
			head=insertAtEnd(head);
			break;
			case 4:
			printf("Enter item after which you want to insert:");
			scanf("%d",&item);
			head=insertAfter(head,item);
			break;
			case 5:
			head=deleteAtBegin(head);
			break;
			case 6:
			head=deleteAtEnd(head);
			break;
			case 7:
			printf("Enter item to delete:");
			scanf("%d",&item);
			head=deleteANode(head,item);
			break;
			case 8:
			head=reverse(head);
			printf("List has been reversed.\n");
			break;
			case 9:
			length(head);
			break;
			case 10:
			return 0;
			default:
			printf("invalid input");
		}
	}
}
