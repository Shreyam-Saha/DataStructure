#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
	struct node *front=NULL,*rear=NULL;
void enqueue()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(ptr));
	printf("\nEnter the value  : ");
	scanf("%d",&ptr->info);
	ptr->next=NULL;
	if(rear==NULL)
	{
		front=ptr;
		rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
void dequeue()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("\nQueue Underflow");
        return;
    }
	temp=front;
	printf("%d dequeued from the queue\n",temp->info);
	front=front->next;
	free(temp);
	if(rear==temp)
		rear=NULL;
}
void traverse()
{
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		printf("%d--",temp->info);
		temp=temp->next;
	}
}
int main()
{
	int i,n,ch;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Traverse\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
					traverse();
					break;
			case 2: dequeue();
					traverse();
					break;
            case 3: traverse();
					break;
            case 0: exit(0);
		}
	}
}
