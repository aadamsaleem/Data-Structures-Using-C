/* PROGRAM TO CREATE AND TRAVERSE A BINARY SEARCH TREE */

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct tnode
{
int info;
struct tnode *l;
struct tnode *r;
} node;
node *root;

void create( )
{
int n, i;
node *newn, *ptr, *pptr;
printf("\n Enter no of nodes:\n");
scanf ("%d", &n);
printf("\n Enter %d values\n", n);
root=(node *) malloc(sizeof(node));
root->l=root->r=NULL;
scanf("%d",&root->info);
for(i=2;i<=n;i++)
{
newn=(node *)malloc(sizeof(node));
newn->l=newn->r=NULL;
scanf("%d",&newn->info);
ptr=root;
while(ptr!=NULL)
{
pptr=ptr;
if(newn->info<ptr->info)
{
ptr=ptr->l;
if(ptr==NULL)
pptr->l=newn;
}
else
{
ptr=ptr->r;
if(ptr==NULL)
pptr->r=newn;
}
}
}
}
void preorder(node *ptr)
{
if(ptr!=NULL)
{
printf("%d ,",ptr->info);
preorder(ptr->l);
preorder(ptr->r);
}
}
void inorder(node*ptr)
{
if(ptr!=NULL)
{
inorder(ptr->l);
printf("%d ,",ptr->info);
inorder(ptr->r);
}
}
void postorder(node*ptr)
{
if(ptr!=NULL)
{
postorder(ptr->l);
postorder(ptr->r);
printf("%d ,",ptr->info);
}
}
void main()
{
clrscr();
create();
printf("\n Preorder traversal:\n");
printf("\n");
preorder(root);
printf("\n inorder traversal:\n");
printf("\n");
inorder(root);
printf("\n postorder traversal:\n");
printf("\n");
postorder(root);
getch();
}
