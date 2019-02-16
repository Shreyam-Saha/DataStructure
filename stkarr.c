#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stk[MAX];
int top=-1;
int stackfull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
int stackempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push()
{
	if(stackfull()==1)
	{
		printf("\nStack Overflow");
		return;
	}
	top+=1;
	printf("\nEnter the value: ");
	scanf("%d",&stk[top]);
}
void pop()
{
	if(stackempty()==1)
	{
		printf("\nStack Underflow");
		return;
	}
	printf("\n%d popped from the stack",stk[top]);
	top--;
}
void traverse()
{
	int i;
	if(stackempty()==1)
	{
		printf("\nStack Underflow");
		return;
	}
	for(i=top;i>=0;i--)
		printf("%d\n",stk[i]);
}
int main()
{
	int n,ch;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Traverse\n0.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
            case 3: traverse();
					break;
            case 0: exit(0);
		}
	}
}
