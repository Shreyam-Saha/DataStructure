#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next,*prev;
};
struct node *create(struct node *head,int n)
{
	struct node *ptr,*temp;
	int i,value;
	if(head!=NULL)
	{
		printf("\nList already exists");
		return(head);
	}
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the value: ");
		scanf("%d",&value);
		ptr=(struct node *)malloc(sizeof(ptr));
		ptr->info=value;
		ptr->next=NULL;
		if(head==NULL)
		{
			head=ptr;
			ptr->prev=NULL;
		}
		else
		{
			temp->next=ptr;
			ptr->prev=temp;
		}
		temp=ptr;
	}
	return(head);
}
struct node *insbeg(struct node *head,int n)
{
	struct node *ptr,*temp;
	if(head==NULL)
	{
		printf("\nList doesn't exist");
		return(head);
	}
	ptr=(struct node *)malloc(sizeof(ptr));
	head->prev=ptr;
	ptr->info=n;
	ptr->next=head;
	ptr->prev=NULL;
	head=ptr;
	return(head);
}
void insend(struct node *head,int n)
{
	struct node *ptr,*temp;
        if(head==NULL)
        {
                printf("\nList doesn't exist");
                return;
        }
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->info=n;
	ptr->next=NULL;
	ptr->prev=temp;
	temp->next=ptr;
        return;
}
struct node *delbeg(struct node *head)
{
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("\nList doesn't exist");
                return(head);
        }
	ptr=head;
	ptr->next->prev=NULL;
	head=ptr->next;
	free(ptr);
	return(head);
}
void delend(struct node *head)
{       
        struct node *ptr,*preptr;
        if(head==NULL)
        {
                printf("\nList doesn't exist");
                return;
        }
        ptr=head;
        while(ptr->next!=NULL)
	{
		preptr=ptr;
                ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}
void traverse(struct node *head)
{
	struct node *temp,*q;
	temp=head;
	while(temp!=NULL)
	{	
		q=temp;
		printf("%d->",temp->info);
		temp=temp->next;
	}
	printf("\n");
	while(q!=NULL)
	{
		printf("<-%d",q->info);
		q=q->prev;
	}
}
int main()
{
	int i,n,ch;
	struct node *head=NULL;
	while(1)
	{
		printf("\n1.Create\n2.Insert Beginning\n3.Insert End\n4.Delete Beginning\n5.Delete End\n6.Traverse\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the number of nodes: ");
				scanf("%d",&n);
				head=create(head,n);
				break;
			case 2: printf("\nEnter the value: ");
                                scanf("%d",&n);
                                head=insbeg(head,n);
                                break;
                        case 3: printf("\nEnter the value: ");
                                scanf("%d",&n);
                                insend(head,n);
                                break;
                        case 4: head=delbeg(head);
                                break;
                        case 5: delend(head);
                                break;
                        case 6: traverse(head);
                                break;
                        case 0: exit(0);
		}
	}
}
