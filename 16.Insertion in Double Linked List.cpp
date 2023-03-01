#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *prev;
	struct node *next;
}*head,*tail;

struct node *newnode,*temp;

void display()
{
	temp=head;
	printf("\n");
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
}

void insert_at_begin()
{
	newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&newnode->data);
	if(head==NULL)
	{
		printf("\nL.L is empty");
		head=tail=newnode;
		newnode->prev=tail;
		newnode->next=head;
    }
    else
    {
    	newnode->prev=head->prev;
    	newnode->next=head;
    	head->prev=newnode;
    	tail->next=newnode;
    	head=newnode;
	}
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
		head=tail=newnode;
		newnode->prev=tail;
		newnode->next=head;
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
		newnode->next->prev=newnode;
	}
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
		head=tail=newnode;
		newnode->prev=tail;
		newnode->next=head;
    }
    else
    {
       newnode->next=tail->next;
       newnode->prev=tail;
       tail->next=newnode;
       head->prev=newnode;
       tail=newnode;
	}
	display();
}

int main()
{
	int n,choice=0,pos;
	printf("Enter no of elements:");
	scanf("%d",&n);
	head=tail=NULL;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data:");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=tail=newnode;
			newnode->prev=tail;
			newnode->next=head;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			newnode->next=head;
			tail=newnode;
		}
	}
	display();
	printf("\n AT BEGIN 2.AT KTH POS 3.AT END");
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

