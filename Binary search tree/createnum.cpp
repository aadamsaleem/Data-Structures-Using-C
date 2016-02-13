/* Create BST for numerals */
# include <stdio.h>
# include <conio.h>
# include <alloc.h>
struct bst
{
int data;
struct bst *lchild;
struct bst *rchild;
}
*root=NULL;
void create_bst (struct bst **bstroot,int item)
{
if (*bstroot==NULL)
{
*bstroot=(struct bst*)malloc(sizeof (struct bst));
(*bstroot)->lchild=NULL;
(*bstroot)->rchild=NULL;
(*bstroot)->data=item;
}
else
{
if (item<(*bstroot)->data)
create_bst(&((*bstroot)->lchild), item);
if (item>(*bstroot)->data)
create_bst (&((*bstroot) ->rchild), item);
}
}
void inorder_traverse (struct bst *bstroot)
{
if (bstroot !=NULL)
{
inorder_traverse (bstroot->lchild);
printf ("\n%d", bstroot->data);
inorder_traverse (bstroot->rchild);
}
}
void preorder_traverse (struct bst *bstroot)
{
if (bstroot !=NULL)
{
printf ("\n%d", bstroot->data);
preorder_traverse (bstroot->lchild);
preorder_traverse (bstroot->rchild);
}
}
void postorder_traverse (struct bst *bstroot)
{
if (bstroot !=NULL)
{
postorder_traverse (bstroot->lchild);
postorder_traverse (bstroot->rchild);
printf ("\n%d", bstroot->data);
}
}
void main ( )
{
clrscr ( );
create_bst (&root, 100);
create_bst (&root, 110);
create_bst (&root, 90);
create_bst (&root, 10);
create_bst (&root, 101);
create_bst (&root, 120);
create_bst (&root, 103);
create_bst (&root, 105);
create_bst (&root, 108);
clrscr ( ) ;
printf ("\nTraversing bst into inorder");
inorder_traverse (root);
printf ("\nTraversing bst into preorder");
preorder_traverse (root);
printf ("\nTraversing bst into postorder");
postorder_traverse (root);
getch ( );
}


