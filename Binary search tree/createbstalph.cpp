/* Create BST for alphabets */

# include <stdio.h>
# include <conio.h>
# include <alloc.h>
struct bst
{
char data;
struct bst *lchild;
struct bst *rchild;
}
*root=NULL;
void create_bst (struct bst **bstroot,char item)
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
create_bst (& ((*bstroot) ->lchild), item);
if (item>(*bstroot)->data)
create_bst (& ( (*bstroot) ->rchild), item);
}
}
void inorder_traverse (struct bst *bstroot)
{
if (bstroot !=NULL)
{
inorder_traverse (bstroot->lchild);
printf ("\n%c", bstroot->data);
inorder_traverse (bstroot->rchild);
}
}
void preorder_traverse (struct bst *bstroot)
{
if (bstroot !=NULL)
{
printf ("\n%c", bstroot->data);
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
printf ("\n%c", bstroot->data);
}
}
void main ( )
{
clrscr ( );
create_bst (&root, 'A');
create_bst (&root, 'B');
create_bst (&root, 'a');
create_bst (&root, 'b');
create_bst (&root, 'C');
create_bst (&root, 'c');
create_bst (&root, 'D');
create_bst (&root, 'd');
create_bst (&root, 'E');
clrscr ( ) ;
printf ("\nTraversing bst into Inorder :\n");
inorder_traverse (root);
printf ("\nTraversing bst into Preorder :\n");
preorder_traverse (root);
printf ("\nTraversing bst into Postorder:\n");
postorder_traverse (root);
getch ( );
}
