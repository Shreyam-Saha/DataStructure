#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *left, *right;

};

typedef struct stack
{
	int top;
	struct node *arr[50];	
}stack;

void Insert_BST(struct node **,int );
void Traverse_Preorder(struct node * );
void Traverse_Inorder(struct node * );
void Traverse_Postorder(struct node * );
void SmallestLargest(struct node *);
int HeightTree(struct node *);
void PreTraverse_NonRecursive(struct node *,stack *);
void PostTraverse_NonRecursive(struct node *, stack *);
void InTraverse_NonRecursive(struct node *, stack *);
void push( stack *,struct node *);
int isEmpty(stack *);
struct node *pop(struct stack*);
void Delete_BST(struct node **, int );
int main()
{
	int ch,item;
	struct node *root=NULL;
	stack s,*ps;
	ps=&s;
	ps->top=-1;
	while(1)
	{
		printf("\n1. Insert\n2. Traverse-Preorder\n3. Traverse-Inorder\n4. Traverse-Postorder\n5. Smallest & Largest Element\n6. Height of Tree\n7. PreTraverse(NonRecursive)\n8. \n10. Delete BST \n  0. Exit\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Node Value:");
				scanf("%d",&item);
				Insert_BST(&root,item);
				break;
			case 2: Traverse_Preorder(root);
				break;
			case 3: Traverse_Inorder(root);
				break;
			case 4: Traverse_Postorder(root);
				break;
			case 5: SmallestLargest(root);
				break;
			case 6: printf("\nHeight of the Tree is %d",HeightTree(root));
				break;
			case 7: PreTraverse_NonRecursive(root,ps);
				break;
			case 8: InTraverse_NonRecursive(root,ps);
				break;
			/*case 9: PostTraverse_NonRecursive(root,ps);
				break;*/
			case 10: printf("Enter the item to be deleted:");
				scanf("%d",&item);
				Delete_BST(&root,item);
				break;
			case 0: exit(0);
		}		
	}
}
void Insert_BST(struct node  **root, int item)
{
	struct node *par,*loc,*newnode;
	par=NULL;
	loc=*root;
	while(loc!=NULL)
	{
		if(item==loc->info)
		{
			printf("Duplicate item....");
			return;
		}
		par=loc;
		if(item<(loc->info))
			loc=loc->left;
		else
			loc=loc->right;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=item;
	newnode->left=NULL;
	newnode->right=NULL;
	if(par==NULL)
		*root=newnode;
	else if (item<(par->info))
		par->left=newnode;
	else
		par->right=newnode;

}

void Traverse_Preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->info);
		Traverse_Preorder(root->left);
		Traverse_Preorder(root->right);
	}

}
void Traverse_Inorder(struct node *root)
{
  if(root!=NULL)
        {   
                Traverse_Inorder(root->left);
		printf("%d\t",root->info);
                Traverse_Inorder(root->right);
        }


}
void Traverse_Postorder(struct node *root)
{
  if(root!=NULL)
       	{
                Traverse_Postorder(root->left);
                Traverse_Postorder(root->right);
		printf("%d\t",root->info);

        }

}
void SmallestLargest(struct node *root)
{
	struct node *loc;
	loc = root;
	while(loc->left != NULL)
		loc=loc->left;
	printf("\nSmallest Element %d",loc->info);
	loc = root;
	while(loc->right != NULL)
		loc=loc->right;
	printf("\nLargest Element %d",loc->info);
}
int HeightTree(struct node *root)
{
	int l,r;
	if(root!=NULL)
	{
		l=1+HeightTree(root->left);
		r=1+HeightTree(root->right);
		if(l>r)
			return(l);
		else
			return(r);
	  
	}
	return(-1);
}
void PreTraverse_NonRecursive(struct node *root, stack *ps)
{
	struct node *loc;
	loc=root;
	while(1)
	{
		while(loc!=NULL)
		{
			printf("%d\t",loc->info);
			push(ps,loc);
			loc=loc->left;
		}
		if(isEmpty(ps))
			return;
		loc=pop(ps);
		loc=loc->right;
	}
	
}
void InTraverse_NonRecursive(struct node *root,stack *ps)
{
	struct node *loc;
        loc=root;
        while(1)
        {
                while(loc!=NULL)
                {
                        push(ps,loc);
                        loc=loc->left;
                }
                if(isEmpty(ps))
                        return;
                loc=pop(ps);
                printf("%d\t",loc->info);
                loc=loc->right;
        }

}

void PostTraverse_NonRecursive(struct node *root,stack *ps)
{
	struct node *ptr,*loc;
        loc=root;
        while(1)
        {
                while(loc!=NULL)
                {
                        push(ps,loc);
                	if(loc->right!=NULL)
                        push(ps,NULL);
                        loc=loc->left;
                }
                if(isEmpty(ps))
                        break;
                ptr=pop(ps);
				if(ptr!=NULL)
					printf("%d",ptr->info);
				else
				{	
                	ptr=pop(ps);
                	loc=loc->right;
                	push(ps,ptr);
        		}
		}        		

}
*/

void push( stack *ps,struct node *loc)
{
	
        ps->top++;
	ps->arr[ps->top]=loc;
	return;
}

struct node *pop(stack *ps)
{
        struct node *ptr;
	ptr=ps->arr[ps->top];
	ps->top--;
	return ptr;
	 
}    
int isEmpty(stack *ps)
{
        if(ps->top==-1)
                return 1;
        else
                return 0;
}
                                             
void Delete_BST(struct node **root,int item)
{
	struct node *par,*loc,*child,*suc,*parsuc;
	par=NULL;
	loc=*root;
	while((loc!=NULL) && (loc->info!=item))
	{
		par=loc;
		if(item<(loc->info))
			loc=loc->left;
		else
			loc=loc->right;
	}
	if(loc==NULL)
	{
		printf("The Tree doesnot exist....");
		return;
	}
	if((loc->left==NULL)&&(loc->right==NULL))
		child=NULL;
	else if (loc->left==NULL)
		child=loc->right;
	else if (loc->right==NULL)
		child=loc->left;
	else
	{
		suc=loc->right;
		parsuc=loc;
		while(suc->left!=NULL)
		{
			parsuc=suc;
			suc=suc->left;	
		}
		if(parsuc!=loc)
		{
			parsuc->left=suc->right;
			suc->right=loc->right;
		}
		suc->left=loc->left;
		child=suc;
	}	
    if(par!=NULL)
	{	
		if(loc==par->left)
			par->left=child;
        else
			par->right=child;
	}
	else
		*root=child;
	loc->left=NULL;
	loc->right=NULL;
	free(loc);
	return ;
}
