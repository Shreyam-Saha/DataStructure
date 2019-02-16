#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int left=-1,right=-1;
int deqfull(int *d)
{
	if((left==0 && right==MAX-1)||(left==right+1))
		return 1;
	else
		return 0;
}
int deqempty(int *d)
{
	if(left==-1 && right==-1)
		return 1;
	else
		return 0;
}
void insl(int *d,int n)
{
	if(deqfull(d)==1)
	{
		printf("\nDeque Overflow");
		return;
	}
	if(left==-1)
	{
		left=MAX-1;
		right=MAX-1;
	}
	else if(left==0)
		left=MAX-1;
	else
		left=left-1;
	d[left]=n;
}
void insr(int *d,int n)
{
	if(deqfull(d)==1)
	{
		printf("\nDeque Overflow");
		return;
	}
		if(right==-1)
	{
		left=0;
		right=0;
	}
	else if(right==MAX-1)
		right=0;
	else
		right=right+1;
	d[right]=n;
}
void dell(int *d)
{
	if(deqempty(d)==1)
	{
		printf("\nDeque Underflow");
		return;
	}
	printf("%d\n",d[left]);
		if(left==right)
	{
		left=-1;
		right=-1;
	}
	else if(left==MAX-1)
		left=0;
	else
		left=left+1;
}
void delr(int *d)
{
	if(deqempty(d)==1)
	{
		printf("\nDeque Underflow");
		return;
	}
	printf("%d\n",d[right]);
		if(right==left)
	{
		right=-1;
		left=-1;
	}
	else if(right==0)
		right=MAX-1;
	else
		right=right-1;
}
int main()
{
	int d[MAX];
	int n,ch;
	while(1)
	{
		printf("\n1.Left Insert\n2.Right Insert\n3.Left Delete\n4.Right Delete\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the value: ");
					scanf("%d",&n);
					insl(d,n);
					break;
			case 2: printf("\nEnter the value: ");
					scanf("%d",&n);
					insr(d,n);
					break;
            case 3: dell(d);
					break;
			case 4: delr(d);
					break;
            case 0: exit(0);
		}
	}
}
