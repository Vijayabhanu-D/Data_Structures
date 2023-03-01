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

void del_at_begin()
{
	if(head==NULL)
	{
		printf("\nL.L is empty");
    }
    else
    {
    	temp=head;
    	head->next->prev=head->prev;
    	tail->next=head->next;
    	head=head->next;
    	free(temp);
	}
	display();
}

void del_at_k()
{
	int pos;
	printf("\nEnter position:");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("\nL.L is empty");
    }
    else
    {
    	temp=head;
        for(int i=1;i<pos;i++)
        {
        	temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
	display();
}

void del_at_end()
{
	if(head==NULL)
	{
		printf("\nL.L is empty");
    }
    else
    {
       tail->prev->next=head;
       head->prev=tail->prev;
       temp=tail;
       tail=tail->prev;
       free(temp);
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
				del_at_begin();
				break;
			case 2:
			    del_at_k();
				break;
			case 3:
			    del_at_end();
				break;
			case 4:
				return 0;
			default:
			    printf("\nEnter an invalid option");	
		}
	}
	return 0;
}

