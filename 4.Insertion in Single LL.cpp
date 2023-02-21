#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *newnode,*head=NULL,*temp,*prev;
int n,choice=0,count;

void display()
{
	temp=head;
	printf("\n");
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
		newnode->next=NULL;
		head=newnode;
    }
    else
    {
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
		newnode->next=NULL;
		head=newnode;
    }
    else
    {
    	temp=head;
        for(int i=0;i<pos-1;i++)
        {
        	prev=temp;
        	temp=temp->next;
		}
		prev->next=newnode;
		newnode->next=temp;
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
        newnode->next=NULL;
	}
	count++;
	display();
}

int main()
{
	printf("\nEnter no of nodes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data:");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=temp=newnode;
			temp->next=NULL;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
			newnode->next=NULL;
		}
		count++;		
	}
	display();
	printf("\n1.Insert at begin 2.Insertion at kth position 3.Insertion at end 4.Exit");
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

