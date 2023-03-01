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

int main()
{
	int n;
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
	return 0;
}
