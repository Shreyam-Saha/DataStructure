#include<stdio.h>
#include<stdlib.h>
struct node
{	 int info;
	struct node *next;
};
void Create(struct node **,int );
void Traverse(struct node *);
void InsertFirst(struct node **, int  );
void InsertLast(struct node *, int );
void DeleteFirst(struct node **);
void DeleteLast(struct node **);
int Count(struct node *);
void Reverse(struct node **);
void Insertpos(struct node **, int , int );
void Deletepos(struct node **,int );
void Deleteitem(struct node **, int);
void Search(struct node **, int );
int main()
{	struct node *head=NULL;
	int num,item;
	int c,pos;
	while(1)
	{
	printf("\nMENU \n 1. Create \n 2. Traverse\n 3. Insert First  \n 4. Insert Last \n 5. Delete First \n 6. Delete Last \n 7. Count \n 8.Reverse \n 9.Insert At Position \n 10. Delete At Position\n 11. Delete by Item\n 12.Search   ENTER YOUR CHOICE:");
	scanf("%d",&c);
	switch(c)
	{
		case 1: printf("ENTER THE NUMBER OF NODES TO CREATE:");
			scanf("%d", &num);
			printf("LIKED LIST BEING CREATED\n");
			Create(&head,num);
			break;
		case 2: Traverse(head);
			break;
		case 3: printf("E3nter the information:");
			scanf("%d",&item );
			InsertFirst(&head,item);
			break; 
		case 4: printf("Enter the informaton:");
			scanf("%d",&item);
			InsertLast(head,item);
			break;
		case 5: DeleteFirst(&head);
			break;
		case 6: DeleteLast(&head);
			break;
		case 7: printf("\nNo. of nodes %d",Count(head));
			br eak;
		case 8: Reverse(&head);
			break;
		case 9: printf("Enter the information:\n");
			scanf("%d",&item);
			printf("\nEnter the position you desire to enter:");
			scanf("%d",&pos);
			Insertpos(&head,item,pos);
			break;	
		case 10:printf("Enter the position to be deleted:");
			scanf("%d",&pos);
			Deletepos(&head,pos);
			break;
		case 11:printf("Enter the item to be deleted:");
			scanf("%d",&item);
			Deleteitem(&head,item);
			break;
		case 12:printf("Enter the element to be searched:");
			scanf("%d",&item);
			Search(&head,item);
			break;
		default: printf("Wrong Choice\n");

	}
	
	}
return 0;
}

void Create(struct node **phead, int n)
{
	struct node *newnode,*temp;
	int i, item;
	if(*phead!=NULL)
	{
		printf("ALREADY CREATED!!!!");
		return;	
	}
	for(i=1;i<=n;++i)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter ihe information: ");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		if(*phead == NULL)
			*phead=newnode;
		else
			temp->next = newnode;		
		temp=newnode;
	}	
	return ;
}


	
void Traverse(struct node *phead)
{
	struct node *loc;
	loc=phead;
	while(loc!=NULL)
	{
		printf("\nINFO : %d\n", loc->info);
		loc=loc->next;
		
	}
	return;
}
void InsertFirst(struct node **phead,int item1)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=item1;
	newnode->next=*phead;
	*phead=newnode;
	return;	
}
void InsertLast(struct node *phead,int item1 )
{	
	struct node *loc, *newnode;
	loc=phead;
	while(loc->next!=NULL)
		loc=loc->next;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=item1;
	newnode->next=NULL;
	loc->next=newnode;
	return;
}
void DeleteFirst(struct node **phead)
{
	struct node *temp;
	temp=*phead;
	*phead=(*phead)->next;
	printf("\n INFO deleted:%d ",temp->info);
	temp->next=NULL;
	free(temp);
	return;
}
void DeleteLast(struct node **phead)
{	if(*phead=NULL)
	{
		printf("List not Created");
		return;
	}
	struct node *loc,*locp;
	loc=*phead;
	while(loc->next!=NULL)
	{
		locp=loc;
		loc=loc->next;
	}
	if (loc==*phead)
		*phead=NULL;
	else
		locp->next=NULL;
	free(loc);
	return;
}
int Count(struct node *head)
{
	struct node *loc;
	int c=0; 
	if(head==NULL)
		printf("\nEmpty list" );
	else
	{
		loc=head;
		while(loc!=NULL)
		{
			loc=loc->next;
			++c;
		}
	}
	return c;
}
 
void Reverse(struct node **phead)
{	
	struct node *loc, *locp, *locn;
	if (*phead==NULL|| (*phead)->next==NULL)
		return;
	loc=*phead;
	locp=NULL;
	while(loc!=NULL)
	{
		locn=loc->next;
		loc->next=locp;
		locp=loc;
		loc=locn;
	}
	*phead=locp;
	return;

}
void Insertpos(struct node **phead,int item, int pos)
{	
	struct node *loc,*newnode;
	int cnt=1;
	if(*phead==NULL)
	{	
		printf("\nEmpty List");
		return;
	}
	if(pos > Count(*phead)+1)	
	{
		printf("\nInvalid position...");
		return;
	}
	loc=*phead;
	newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=item;
	while(loc!=NULL && ((pos-1)>cnt))
	{
		loc=loc->next;
		cnt++;
	}
	if (loc==*phead)
        {
                newnode->next= loc;
                *phead=newnode;
        }
	else
	{
		newnode->next=loc->next;
		loc->next=newnode;
	}
	return;
}

void Deletepos(struct node **phead,int pos)
{
	struct node *loc, *locp;
	int cnt=1;
	if (*phead==NULL)
	{	
		printf("\nEmpty List");
		return;
	}
	loc=*phead;
	while(loc!=NULL && ((pos)>cnt))
	{	locp=loc;
		loc=loc->next;
		cnt++;
	}
	
	
	locp->next=loc->next;
	loc->next=NULL;
	free(loc);
	return;
}
void Deleteitem(struct node **phead,int item)
{
	struct node *loc,*locp;
	
	if (*phead==NULL)
	{
		printf("\nEmpty List");
		return;
	}
	loc=*phead;
	while(loc!=NULL)
	{
		if((loc->info)==item)
			break;
		locp=loc;
		loc=loc->next;
	}
	if(loc==NULL)
	{
		printf("Data not found.......");
		return;
	}
	locp->next=loc->next;
	loc->next=NULL;
	free(loc);

}

void Search(struct node **phead, int item)
{
	struct node *loc;
	int p=0;
	if(*phead=NULL)
	{
		printf("\nEmpty list....");
		return;
	}
	while(loc!=NULL)
	{
		if((loc->info)==item)
		{
			p=1;
			break;
		}
		loc=loc->next;
	}
	if(p==1)
		printf("\n The item exists in the list.......");
	else
		printf("\n The item does not exists.....");
	return;
}
	
