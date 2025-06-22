#include<stdio.h> 
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *createNode()
{
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	return newNode;
}
struct node *insertAtBegin(struct node *head)
{
	struct node *temp,*newNode;
	newNode=createNode();
	temp=head;
	if(temp==NULL)
	{
		head=newNode;
		newNode->next=head;
	}
	else
	{
		while(temp->next!=head)
		temp=temp->next;
		temp->next=newNode;
		newNode->next=head;
		head=newNode;
	}
	return head;
}
struct node *insertAtEnd(struct node *head)
{
	struct node *temp,*newNode;
	newNode=createNode();
	temp=head;
	if(temp==NULL)
	{
		head=newNode;
		newNode->next=head;
	}
	else
	{
		while(temp->next!=head)
		temp=temp->next;
		temp->next=newNode;
		newNode->next=head;
	}
	return head;
}
struct node *insertAfter(struct node *head,int key)
{
	struct node *temp,*newNode;
	newNode=createNode();
	temp=head;
	if(temp==NULL)
	printf("Node not found.\n");
	else
	{
		while(temp->next!=head && temp->data!=key)
			temp=temp->next;
		if(temp->data==key)
		{
			newNode->next=temp->next;
			temp->next=newNode;
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
	{
		printf("list is empty");
	}

	while(temp->next!=head) 
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
	
	
}
struct node *deleteAtBegin(struct node *head)
{
	struct node *temp,*p;
	p=temp=head;
	if(temp==NULL)
	printf("List is empty. Deletion is not possible.\n");
	else if(temp->next==head)
	{
		head=NULL;
		free(head);
	}
	else
	{
		while(p->next!=head)
			p=p->next;
		p->next=temp->next;
		head=temp->next;
		free(temp);
	}
	return head;
}

struct node *deleteAtEnd(struct node *head)
{
	struct node *p,*temp;
	temp=p=head;
	
	if(temp==NULL)
	{
		printf("the list is empty deletion cant be possible.\n");
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
	}
	else
	{
		while(temp->next->next!=head)
		{
			temp=temp->next;
		}
		p=temp->next;
		temp->next=head;
		free(p);
	}
	return head;
}
struct node *deleteANode(struct node *head,int key)
{
	struct node *prev=NULL,*temp,*p;
	temp=head;
	if(temp==NULL)
	printf("List is empty, deletion not possible.\n");
	else if(temp->data==key && temp->next==head)
	{
		head=NULL;
		free(head);
	}
	else if(temp->data!=key && temp->next==head)
		printf("Node not found.\n");
	else if(temp->data==key && temp->next!=head)
	{
		p=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=p->next;
		head=p->next;
		free(p);
	}
	else
	{
		while(temp->data!=key && temp->next!=head)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp->data==key)
		{
			prev->next=temp->next;
			free(temp);
		}
		else
		printf("Node not found.\n");
	}
	return head;
}
int main()
{
	int ch,item;
	struct node *head=NULL;
	printf("1.Display\n2.Insert at beginning\n3.Insert at ending\n4.Insert after an item\n5.Delete at front\n6.Delete at end\n7.Delete a node\n8.Exit\n");
	while(1)
	{
		
		printf("Enter your choice:\n");
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
			return 0;
			default:
			printf("invalid input");
		}
	}
}
