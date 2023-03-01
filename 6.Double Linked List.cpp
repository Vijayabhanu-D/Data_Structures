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

int main()
{
	int n;
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
	return 0;
}
