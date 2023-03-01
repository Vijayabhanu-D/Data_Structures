#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node*next;
}*head;

struct node *newnode,*temp,*temp1;

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

void del_at_beg()
{
	temp=head;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=head->next;
		head=head->next;
	}
	display();
}

void del_at_pos()
{
	int pos;
	printf("\nEnter position:");
	scanf("%d",&pos);
	if(pos==1)
	{
		del_at_beg();
	}
	else
	{
	    temp=temp1=head;
	    for(int i=1;i<pos;i++)
	    {
	    	temp1=temp;
	    	temp=temp->next;
		}
		temp1->next=temp->next;
		free(temp);
	}
	display();
}

void del_at_end()
{
	temp=temp1=head;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		while(temp->next!=head)
		{
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=temp->next;
		free(temp);
	}
	display();
}

int main()
{
	int n,choice=0;
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
	while(choice!=4)
	{
		printf("\n1.Delete at beg 2.Delete at kth pos 3.Delete at end 4.Exit");
		printf("\nEnter choice:");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 1:
	    		del_at_beg();
	    		break;
	    	case 2:
	    		del_at_pos();
	    		break;
	    	case 3:
	    		del_at_end();
	    		break;
	    	case 4:
	    		return 0;
	    	default:
	    		printf("\nEntered invalid choice!");
		}
	}
	return 0;
}
