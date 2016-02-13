#include <stdio.h>
#include <conio.h>
#include <malloc.h>

enum boolean
{
    false=0,
    true=1
};

struct thtree
{
    enum boolean isleft;
    struct thtree *left;
    int data;
    struct thtree *right;
    enum boolean isright;
};

void insert(struct thtree **,int);
void delete(struct thtree **,int);
void search(struct thtree **,int,struct thtree **,struct thtree **,int *);
void inorder(struct thtree *);
void deltree(struct thtree **);

int main()
{
	struct thtree *th_head;
	int elem,choice;
	th_head=NULL;
	while(1)
	{
		
		system("cls");
        printf("\n\n\t\t\t\t THREADED BINARY TREE\n\t\t\t\t   by Aadam Saleem\n\t\t\t\t   11-CSS-01\n\n\n");
        if(th_head!=NULL)
            inorder(th_head);
		printf("\n\n\t\t1.Insert\n");
        printf("\t\t2.Delete\n");
        printf("\t\t3.Inoreder\n");
        printf("\t\t4.Delete Tree\n");
        printf("\t\t5.Quit\n");
		printf("\n\n\t\tEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("\n\t\tEnter the number to be inserted : ");
			scanf("%d",&elem);
			insert(&th_head,elem);
			break;

			case 2:
			printf("\n\t\tEnter the number to be deleted : ");
			scanf("%d",&elem);
			delete(&th_head,elem);
			inorder(th_head);
			break;

			case 3:
			printf("\nInorder  :\n");
			inorder(th_head);
			getch();
			break;

			case 4:
			deltree(&th_head);
			inorder(th_head);
			break;

			case 5:
			exit(1);
			break;

			default:
			printf("\n\t\tWrong choice!\n");
			break;

		}
	}
}

void insert(struct thtree **s,int num)
{
    struct thtree *p,*z,*head=*s;
    z=malloc(sizeof(struct thtree));
    z->isleft=true;
    z->data=num;
    z->isright=true;
    if(*s==NULL)
    {
        head=malloc(sizeof(struct thtree));
        
        head->isleft=false;
        head->left=z;
        head->data=-9999;
        head->right=head;
        head->isright=false;
        *s=head;
        z->left=head;
        z->right=head;
    }	
    else
    {
  p=head->left;
 
 while(p!=head)
        {
            if(p->data > num)
            {
                if(p->isleft!=true)
                    p=p->left;
                else
                {
                    z->left=p->left;
                    p->left=z;
                    p->isleft=false;
                    z->isright=true;
                    z->right=p;
                    return;
                }
            }
            else
            {
                if(p->data < num)
                {
                    if(p->isright!=true)
                    p=p->right;
                    else
                    {
                        z->right=p->right;
                        p->right=z;
                        p->isright=false;
                        z->isleft=true;
                        z->left=p;
                        return;
                    }
                }
            }
        }
    }
}

void delete(struct thtree **root,int num)
{
    int found;
    struct thtree *parent,*x,*xsucc;
   
   if(*root==NULL)
   {
        printf("\nTree is empty");
        return;
    }
    parent=x=NULL;
    
    search(root,num,&parent,&x,&found);
    
    if(found==false)	
    {
             printf("\nData to be deleted,not found");
                        return;
    }
    				
if(x->isleft==false && x->isright==false)
{
        parent=x;
        xsucc=x->right;
        while(xsucc->isleft==false)
        {
            parent=xsucc;
            xsucc=xsucc->left;
        }
        x->data=xsucc->data;
        x=xsucc;
 }

if(x->isleft==true && x->isright==true)
{
        
        if(parent==NULL)
        {
           (*root)->left=*root;
           (*root)->isleft=true;
            free(x);
            return;
        }
        if(parent->right==x)
        {
            parent->isright=true;
            parent->right=x->right;
        }
        else
        {
            parent->isleft=true;
            parent->left=x->left;
        }
        free(x);
        return;
    }
    
    if(x->isleft==true && x->isright==false)
    {
        			
       if(parent==NULL)
        {
           (*root)->left=x->right;
            free(x);
            return;
        }
        if(parent->left==x)	
        {
            parent->left=x->right;
            x->right->left=x->left;
        }
        else
        {
            parent->right=x->right;
            x->right->left=parent;
        }
        free(x);
        return;
    }
    	
    if(x->isleft==false && x->isright==true)
    {
        
        if(parent==NULL)
        {
            parent=x;
            xsucc=x->left;
            while(xsucc->right==false)
            xsucc=xsucc->right;
            xsucc->right=*root;
           (*root)->left=x->left;
            free(x);
            return;
        }
        if(parent->left==x)
        {
            parent->left=x->left;
            x->left->right=parent;
        }
        else
        {
            parent->right=x->left;
            x->left->right=x->right;
        }
        free(x);
        return;
    }
}

void search(struct thtree **root,int num,struct thtree **par,struct thtree **x,int *found)
{
    struct thtree *q;
    q =(*root)->left;
    *found=false;
    *par=NULL;
    while(q!=*root)
    {
      
if(q->data==num)
        	{
           *found=true;
            *x=q;
            return;
        		}
        		*par=q;
        		if(q->data > num)
        		{
            		if(q->isleft==true)
            		{
                			*found=false;
                			x=NULL;
                			return;
            		}
            		q=q->left;
        		}
        		else
        		{
            		if(q->isright==true)
           			{
                			*found=false;
                			*x=NULL;
                			return;
            	}
            	q=q->right;
        	}
    }
}

void inorder(struct thtree *root)
{
    struct thtree *p;
    p=root->left;
    printf("\n\n\t\tINORDER OF THE THREADED TREE IS:\n\t\t");
    while(p!=root)
    {
        while(p->isleft==false)
            p=p->left;
            printf("%d  ",p->data);
        while(p->isright==true)
        {
            p=p->right;
            if(p==root)
                break;
            printf("%d  ",p->data);
        }
        p=p->right;
    }
}

void deltree(struct thtree **root)
{
    while(( *root)->left!=*root)
    delete(root,(*root)->left->data);
}
