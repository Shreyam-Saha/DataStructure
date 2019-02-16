#include<stdio.h>
#include<stdlib.h>
struct node
{
        int co,ex;
        struct node *next;
};
struct node *create(struct node *head,int n)
{
	struct node *ptr,*temp;
	int i,c,e;
	temp=head;

	for(i=1;i<=n;i++)
{	
	printf("\nEnter the coefficient: ");
	scanf("%d",&c);
	printf("\nEnter the exponent: ");
	scanf("%d",&e);
	ptr=(struct node *)malloc(sizeof(ptr));
	
	ptr->co=c;
	ptr->ex=e;
	ptr->next=NULL;
	if(head==NULL)
		head=ptr;
	else
	temp->next=ptr;
	temp=ptr;
}
	return(head);
}
void traverse(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%dx^%d",temp->co,temp->ex);
		if(temp->next!=NULL)
			printf("+");
		temp=temp->next;
	}
}
struct node *createpoly(struct node *head,int n,int x)
{
		struct node *ptr,*temp=head;
		ptr=(struct node *)malloc(sizeof(struct node ));
		ptr->co=n;
		ptr->ex=x;
		ptr->next=NULL;
		if(head==NULL)
		{
			head=ptr;
			return head;
		}
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
	return head;
}	
struct node *addpoly(struct node *head1,struct node *head2,struct node *head3)
{
	struct node *temp1,*temp2;
	int x;
	temp1=head1;
	temp2=head2;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->ex==temp2->ex)
			x=temp1->co+temp2->co;
		if(x!=0)
		{
			head3=createpoly(head3,x,temp1->ex);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->ex<temp2->ex)
		{
			head3=createpoly(head3,temp2->co,temp2->ex);
			temp2=temp2->next;
		}
		else if(temp1->ex>temp2->ex)
		{
			head3=createpoly(head3,temp1->co,temp1->ex);
			temp1=temp1->next;
		}
	}
	while(temp1!=NULL)
	{
		head3=createpoly(head3,temp1->co,temp1->ex);
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		head3=createpoly(head3,temp2->co,temp2->ex);
		temp2=temp2->next;
	}
	return(head3);
}	
int main()
{
	int n,c,e,ch;
	struct node *head=NULL,*head1=NULL,*head2=NULL,*head3=NULL;
	while(1)
	{
		printf("\n1.Create Polynomial\n2.Traverse\n3.Add Polynomial\n0.Exit\nEnter your choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: 
				printf("\nEnter node number for 1st polynomial ");
				scanf("%d",&n);
				head1=create(head1,n);
				printf("\nEnter node number for 2nd polynomial ");
				scanf("%d",&n);
				head2=create(head2,n);
                                break;
                        case 2: traverse(head);
                                break;
                        case 3: 
				head3=addpoly(head1,head2,head3);
				printf("\n-----------------------------\n");
				traverse(head3);
                                break;
			case 0: exit(0);
		}
	}
}
