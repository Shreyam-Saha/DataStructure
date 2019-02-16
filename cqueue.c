#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1,rear=-1;
int queuefull()
{
	if((front==0 && rear==MAX-1)||(front==rear+1))
		return 1;
	else
		return 0;
}
int queueempty()
{
	if(front==-1 && rear==-1)
		return 1;
	else
		return 0;
}
void enqueue(int *q,int n)
{
	if(queuefull()==1)
	{
		printf("\nQueue Overflow");
		return;
	}
		if(queueempty()==1)
	{
		front=0;
		rear=0;
	}
	else if(rear==MAX-1)
		rear=0;
	else
		rear=rear+1;
	q[rear]=n;
}
void dequeue(int *q)
{
	if(queueempty()==1)
	{
		printf("\nQueue Underflow");
		return;
	}
	printf("%d\n",q[front]);
		if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
		front=0;
	else
		front=front+1;
}
void display(int *q)
{
	int i;
	if(front>rear)
	{
		for(i=front;i<=MAX;i++)
			printf("%d ",q[i]);
		for(i=0;i<=rear;i++)
			printf("%d ",q[i]);
	}
	else
	{
		for(i=front;i<=rear;i++)
			printf("%d ",q[i]);
	}
}
int main()
{
	int q[MAX];
	int n,ch;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the value: ");
					scanf("%d",&n);
					enqueue(q,n);
					break;
			case 2: dequeue(q);
					break;
            case 3: display(q);
					break;
            case 0: exit(0);
		}
	}
}
