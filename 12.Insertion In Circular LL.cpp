#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node*next;
}*head;

struct node *newnode,*temp;

void display()
{
	printf("\n");
	temp=head;
	do
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}while(temp!=head);
}

void insert_at_beg()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data");
	temp=head;
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		printf("List is empty");
		head=temp=newnode;
		temp->next=head;
	}
	else
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=head;
		head=newnode;
	}
	display();
}

void insert_at_pos()
{
	int pos;
	printf("\nEnter position:");
	scanf("%d",&pos);
	if(pos==1)
	{
		insert_at_beg();
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
	    printf("\nEnter data");
	    scanf("%d",&newnode->data);
	    temp=head;
	    for(int i=1;i<pos-1;i++)
	    {
	    	temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	display();
}

void insert_at_end()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data");
	temp=head;
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		printf("List is empty");
		head=temp=newnode;
		temp->next=head;
	}
	else
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=head;
		temp=newnode;
	}
	display();
}

int main()
{
	int n,choice=0;
	printf("\nEnter no of elements:");
	scanf("%d",&n);
	head=NULL;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data for %d node:",i+1);
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=temp=newnode;
			temp->next=temp;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
			temp->next=head;
	    }
	}
	display();
	while(choice!=4)
	{
		printf("\n1.Insert at beg 2.Insert at kth pos 3.Insert at end 4.Exit");
		printf("\nEnter choice:");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 1:
	    		insert_at_beg();
	    		break;
	    	case 2:
	    		insert_at_pos();
	    		break;
	    	case 3:
	    		insert_at_end();
	    		break;
	    	case 4:
	    		return 0;
	    	default:
	    		printf("\nEntered invalid choice!");
		}
	}
	return 0;
}
