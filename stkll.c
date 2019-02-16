#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *push(struct node *top,int n)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(ptr));
	ptr->info=n;
	ptr->next=top;
	top=ptr;
}
struct node *pop(struct node *top)
{
    struct node *temp;
    if(top==NULL)
    {
        printf("\nStack Underflow");
        return;
    }
	printf("%d popped from the stack",top->info);
	temp=top;
	top=top->next;
	free(temp);
	return (top);
}
void traverse(struct node *top)
{
	struct node *temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}
int main()
{
	int i,n,ch;
	struct node *top=NULL;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Traverse\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the value: ");
					scanf("%d",&n);
					top=push(top,n);
					break;
			case 2: top=pop(top);
					break;
            case 3: traverse(top);
					break;
            case 0: exit(0);
		}
	}
}
