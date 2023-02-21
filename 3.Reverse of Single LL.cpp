#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int main()
{
	int n;
	printf("\nEnter no of nodes:");
	scanf("%d",&n);
	struct node *newnode,*head=NULL,*temp,*prevnode,*nextnode;
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
	}
	temp=head;
	printf("\nLinked List Is :\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\nReverse Of Linked List Is :");
	temp=nextnode=head;
	prevnode=NULL;
	while(nextnode->next!=NULL)
	{
		nextnode=nextnode->next;
		temp->next=prevnode;
		prevnode=temp;
		temp=nextnode;
	}
	head=temp;
	head->next=prevnode;
	
	printf("\n");
	
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
	return 0;
}

