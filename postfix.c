#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
char q[MAX],r[MAX],s[MAX];
int top=-1;
void push(char n)
{
	top++;
	s[top]=n;
}
char pop()
{
	char x;
	x=s[top];
	top--;
	return x;
}
int priority(char y)
{
	if(y=='+' || y=='-')
		return 1;
	if(y=='*' || y=='/')
		return 2;
	if(y=='^')
		return 3;
	else
		return 0;
}
void postfix()
{
	int i,m,j=0,len;
	char ch;
	len=strlen(q);
	q[len]=')';
	push('(');
	for(i=0;i<=len;i++)
	{
		if(isalpha(q[i]))
			r[j++]=q[i];
		else if(q[i]=='(')
			push(q[i]);
		else if(q[i]==')')
		{
			while(s[top]!='(')
				r[j++]=pop();
			ch=pop();
		}
		else
		{
			while(priority(s[top])>=priority(q[i]))
				r[j++]=pop();
			push(q[i]);
		}
	}
	r[j]='\0';
}
int main()
{
	printf("\nEnter the expression: ");
	gets(q);
	printf("\nThe postfix expression is: ");
	postfix();
	puts(r);
}