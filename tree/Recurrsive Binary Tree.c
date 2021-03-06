#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node
{
    int info;
    struct node *l;
    struct node *r;
}*root;

void main()
{
    int choice,num;
    root=NULL;
    while(1)
    {
	    system("cls");
		printf("\n\n\t\t\t\t RECURSIVE BINARY SEARCH TREE\n\t\t\t\t\tby Aadam Saleem\n\t\t\t\t\t11-CSS-01\n\n");
		display(root,1);
        printf("\n\n\t\t1.Insert\n");
        printf("\t\t2.Delete\n");
        printf("\t\t3.Recursive Traversal\n");
        printf("\t\t4.Display\n");
        printf("\t\t5.Quit\n");
        printf("\n\n\t\tEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
         case 1:
            printf("\n\tEnter the number to be inserted : ");
            scanf("%d",&num);
            insert(num);
            break;
         case 2:
            display(root,1);
            printf("\n\tEnter the number to be deleted : ");
            scanf("%d",&num);
            del(num);
            display(root,1);
            break;
         case 3:
            display(root,1);
		 	printf("\n\t\tPreorder   : ");
		 	preorder(root);
		 	printf("\n\t\tInorder    : ");
		 	inorder(root);
		 	printf("\n\t\tPostorder  : ");
		 	postorder(root);
		 	getch();
		 	break;
         case 4:
            display(root,1);
            getch();
            break;
         case 5:
            exit(1);
         default:
            printf("Wrong choice\n");
        }
    }
}

search(int item,struct node **par,struct node **loc)
{
    struct node *ptr,*ptrsave;

    if(root==NULL)
    {
        *loc=NULL;
        *par=NULL;
        return;
    }
    if(item==root->info)
    {
        *loc=root;
        *par=NULL;
        return;
    }

    if(item<root->info)
        ptr=root->l;
    else
        ptr=root->r;
    ptrsave=root;

    while(ptr!=NULL)
    {
        if(item==ptr->info)
        {       *loc=ptr;
            *par=ptrsave;
            return;
        }
        ptrsave=ptr;
        if(item<ptr->info)
            ptr=ptr->l;
        else
            ptr=ptr->r;
     }
     *loc=NULL;
     *par=ptrsave;
	 
}

insert(int item)
{       
    struct node *tmp,*parent,*loc;
    search(item,&parent,&loc);
    if(loc!=NULL)
    {
        printf("\n\t\tItem already present");
        getch();
        return;
    }

    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=item;
    tmp->l=NULL;
    tmp->r=NULL;

    if(parent==NULL)
        root=tmp;
    else
        if(item<parent->info)
            parent->l=tmp;
        else
            parent->r=tmp;
}

del(int item)
{
    struct node *parent,*loc;
    if(root==NULL)
    {
        printf("\n\t\tTree empty");
        getch();
        return;
    }

    search(item,&parent,&loc);
    if(loc==NULL)
    {
        printf("\n\t\tItem not present in tree");
        getch();
        return;
    }

    if(loc->l==NULL && loc->r==NULL)
        del_root(parent,loc);
    if(loc->l!=NULL && loc->r==NULL)
        one_child(parent,loc);
    if(loc->l==NULL && loc->r!=NULL)
        one_child(parent,loc);
    if(loc->l!=NULL && loc->r!=NULL)
        both_child(parent,loc);
    free(loc);
}

del_root(struct node *par,struct node *loc )
{
    if(par==NULL)
        root=NULL;
    else
        if(loc==par->l)
            par->l=NULL;
        else
            par->r=NULL;
}

one_child(struct node *par,struct node *loc)
{
    struct node *child;

    if(loc->l!=NULL)
        child=loc->l;
    else
        child=loc->r;

    if(par==NULL )
        root=child;
    else
        if( loc==par->l)
            par->l=child;
        else
            par->r=child;
}

both_child(struct node *par,struct node *loc)
{
    struct node *ptr,*ptrsave,*suc,*parsuc;

    ptrsave=loc;
    ptr=loc->r;
    while(ptr->l!=NULL)
    {
        ptrsave=ptr;
        ptr=ptr->l;
    }
    suc=ptr;
    parsuc=ptrsave;

    if(suc->l==NULL && suc->r==NULL)
        del_root(parsuc,suc);
    else
        one_child(parsuc,suc);

    if(par==NULL)
        root=suc;
    else
        if(loc==par->l)
            par->l=suc;
        else
            par->r=suc;

    suc->l=loc->l;
    suc->r=loc->r;
}

preorder(struct node *ptr)
{
    if(root==NULL)
    {
        printf("\n\t\tTree is empty");
        return;
    }
    if(ptr!=NULL)
    {
        printf("%d  ",ptr->info);
        preorder(ptr->l);
        preorder(ptr->r);
    }
}

inorder(struct node *ptr)
{
    if(root==NULL)
    {
        printf("\n\t\tTree is empty");
        return;
    }
    if(ptr!=NULL)
    {
        inorder(ptr->l);
        printf("%d  ",ptr->info);
        inorder(ptr->r);
    }
}

postorder(struct node *ptr)
{
    if(root==NULL)
    {
        printf("\n\t\tTree is empty");
        return;
    }
    if(ptr!=NULL)
    {
        postorder(ptr->l);
        postorder(ptr->r);
        printf("%d  ",ptr->info);
    }
}


display(struct node *ptr,int level)
{
    int i;
    if ( ptr!=NULL )
    {
        display(ptr->r, level+1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->info);
        display(ptr->l, level+1);
    }
}
