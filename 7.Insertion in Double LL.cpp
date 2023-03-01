#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *newnode,*head,*temp;
int n,choice=1,count=0;

void display()
{
	printf("\nDouble Linked List is :\n");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

void insert_at_begin()
{
	newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&newnode->data);
	if(head==NULL)
	{
		printf("\nL.L is empty");
		newnode->prev=NULL;
		newnode->next=NULL;
		head=newnode;
    }
    else
    {
    	newnode->prev=NULL;
        newnode->next=head;
        head=newnode;
	}
	count++;
	display();
}

void insert_at_k()
{
	int pos;
	printf("\nEnter position:");
	scanf("%d",&pos);
	newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&newnode->data);
	if(head==NULL)
	{
		printf("\nL.L is empty");
		newnode->prev=NULL;
		newnode->next=NULL;
		head=newnode;
    }
    else
    {
    	temp=head;
        for(int i=1;i<pos-1;i++)
        {
        	temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->prev=temp;
	}
	count++;
	display();
}

void insert_at_end()
{
	newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&newnode->data);
	if(head==NULL)
	{
		printf("\nL.L is empty");
		newnode->prev=NULL;
		newnode->next=NULL;
		head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
        	temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
        newnode->next=NULL;
	}
	count++;
	display();
}

int main()
{
	printf("Enter no of nodes:");
	scanf("%d",&n);
	head=NULL;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data:");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			newnode->prev=NULL;
			newnode->next=NULL;
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next=NULL;
			temp=newnode;
		}
		count++;
	}
	display();
	while(choice != 4)
	{
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_at_begin();
				break;
			case 2:
			    insert_at_k();
				break;
			case 3:
			    insert_at_end();
				break;
			default:
			    printf("\nEnter an invalid option");	
		}
	}
	return 0;
}
