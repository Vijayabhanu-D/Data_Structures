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
	struct node *newnode,*head=NULL,*temp;
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
	int count=0;
	temp=head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
		count++;
	}
	printf("\nLength is %d",count);
	return 0;
}

