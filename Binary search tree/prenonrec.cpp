/* Program to implement BST and traverse in Preorder without using recursion*/

#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#define MAXSIZE 10
int i, top=0, stack [MAXSIZE] ;
struct bst
{
int data;
struct bst *lchild;
struct bst *rchild;
}
*root=NULL;
void insert (struct bst **bstroot, int item)
{
if (*bstroot ==NULL)
{
*bstroot = (struct bst*) malloc (sizeof (struct bst) );
(*bstroot)->lchild=NULL;
(*bstroot)->rchild=NULL;
(*bstroot)->data=item;
}
else
{
if (item<(*bstroot)->data)
insert (& ( (*bstroot)->lchild), item) ;
if (item>(*bstroot)->data)
insert (& ( (*bstroot)->rchild), item) ;
}
}
void preorder (struct bst *node)
{
top = 1 ;
stack [0] = NULL;
node = root;
while(node != NULL)
{
printf ("%d", node -> data) ;
if (node ->rchild !=NULL)
{
top++;
stack[top]=node;
node = node->lchild ;
}
if (node ->lchild !=NULL)
node = node ->rchild;
else
{
node = stack [top];
top--;
}
}
}
void main ( )
{
clrscr ( );
insert (&root, 20);
insert (&root, 60);
insert (&root, 40);
insert (&root, 10);
insert (&root, 30);
insert (&root, 50);
insert (&root, 25);
insert (&root, 28);
insert (&root, 29);
clrscr ( ) ;
printf ("\n Traversing BST into preorder :") ;
preorder (root) ;
getch ( ) ;
}
