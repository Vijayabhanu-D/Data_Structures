#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node*next;
};

struct node *newnode,*temp;

void display()
{
	printf("\n");
	struct node *pre;
	temp=pre=newnode->next;
	do{
		printf("%d ",pre->data);
		pre=pre->next;
	}while(temp!=pre);
}

int main()
{
	int n;
	printf("\nEnter no of elements:");
	scanf("%d",&n);
	temp=NULL;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data for %d node:",i+1);
		scanf("%d",&newnode->data);
		if(temp==NULL)
		{
			temp=newnode;
			temp->next=temp;
		}
		else
		{
			newnode->next=temp->next;
			temp->next=newnode;
			temp=newnode;
	    }
	}
	display();
	return 0;
}
