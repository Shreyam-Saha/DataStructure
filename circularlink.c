#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
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
		if(head==NULL)
		{
			head=ptr;
		}
		else
		{
			temp->next=ptr;
		}
		temp=ptr;
	}
	ptr->next=head;
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
	ptr->info=n;
	temp=head;
	while(temp->next!=head)
	{	
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->next=head;
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
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->info=n;
        temp=head;
        while(temp->next!=head)
                temp=temp->next;
        temp->next=ptr;
        ptr->next=head;
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
	temp=head;
	ptr=head;
        while(temp->next!=head)
	{
		temp=temp->next;
	}
	head=head->next;
	temp->next=head;
	free(ptr);
	return(head);
}
struct node *delend(struct node *head)
{       
        struct node *temp,*pretmp;
        if(head==NULL)
        {
                printf("\nList doesn't exist");
                return(head);
        }
        temp=head;
        while(temp->next!=head)
	{
		pretmp=temp;
                temp=temp->next;
	}
	if(temp == head)
		head=NULL;
	else
		pretmp->next=temp->next;
	free(temp);
	return(head);
}
void traverse(struct node *head)
{
	struct node *temp;
	temp=head;
	do
	{
		printf("%d ",temp->info);
		temp=temp->next;
	}while(temp!=head);
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
                        case 5: head=delend(head);
                                break;
                        case 6: traverse(head);
                                break;
                        case 0: exit(0);
		}
	}
}
