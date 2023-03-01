#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head,*tail;

void display()
{
	struct node *temp=head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
}

void reverse()
{
	struct node *current=head,*nextnode=head;
	while(current!=0)
	{
		nextnode=current->next;
		current->next=current->prev;
		current->prev=nextnode;
		current=nextnode;
	}
	current=tail;
	tail=head;
	head=current;
	
	display();
}

int main()
{
	int n;
	printf("\nEnter no of elements:");
	scanf("%d",&n);
	struct node *newnode;
	head=NULL;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data for %d node:",i+1);
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			newnode->prev=NULL;
			newnode->next=NULL;
			head=tail=newnode;
		}
		else
		{
			newnode->prev=tail;
			tail->next=newnode;
			newnode->next=NULL;
			tail=newnode;
		}
	}
	display();
	reverse();
}
