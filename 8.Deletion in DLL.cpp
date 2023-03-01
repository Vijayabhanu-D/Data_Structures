#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *newnode,*head,*temp;

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

void delete_at_begin()
{
	temp=head;
	if(head==NULL)
	{
		printf("\nL.L is empty");
    }
    else
    {
	    temp=head;	
        head=head->next;
        head->prev=NULL;
        free(temp);
	}
	display();
}

void delete_at_k()
{
	int pos;
	if(head==NULL)
	{
		printf("\nL.L is empty");
    }
    else
    {
    	printf("\nEnter position:");
	    scanf("%d",&pos);
    	temp=head;
        for(int i=0;i<pos-1;i++)
        {
        	temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
	display();
}

void delete_at_end()
{
	if(head==NULL)
	{
		printf("\nL.L is empty");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
        	temp=temp->next;
		}
		temp->prev->next=NULL;
        free(temp);
	}
	display();
}


int main()
{
	int n,choice=1;
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
	}
	display();
	printf("\n1.Delete at begin 2.Delete at kth position 3.Delete at end 4.Exit");
	while(choice != 4)
	{
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				delete_at_begin();
				break;
			case 2:
			    delete_at_k();
				break;
			case 3:
			    delete_at_end();
				break;
			default:
			    printf("\nEnter an invalid option");	
		}
	}
	return 0;
}
