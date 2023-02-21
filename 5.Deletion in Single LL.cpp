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
        free(temp);
	}
	count--;
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
        	prev=temp;
        	temp=temp->next;
		}
		prev->next=temp->next;
		free(temp);
	}
	count--;
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
        temp=prev=head;
        while(temp->next!=NULL)
        {
        	prev=temp;
        	temp=temp->next;
		}
		prev->next=NULL;
        free(temp);
	}
	count--;
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
		count--;		
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

