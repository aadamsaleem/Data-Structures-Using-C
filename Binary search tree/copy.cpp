/* Copy the binary tree */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
long num;
struct node *left;
struct node *right;
};
struct node *tree,*second,*head;
struct node *insert(struct node *tree,long num);
struct node *copy(struct node *tree);
void inorder(struct node *tree);
int select();

void main()
{
clrscr();
int ch;
long digit;
do
{
ch=select();
switch(ch)
{
case 1:puts("Enter integers:To quit enter 0");
scanf("%ld",&digit);
while(digit!=0)
{
tree=insert(tree,digit);
scanf("%ld",&digit);
}
continue;
case 2: copy(tree);
puts("Tree is copied ..");
continue;
case 3: puts("Inorder traversing");
inorder(tree);
continue;
case 4:
exit(0);
}
}while(ch!=4);
}
int select()
{
int sel;
do
{
puts("Enter 1: Insert a node in the BST");
puts("Enter 2: Copy a tree to another BST");
puts("Enter 3: Display(inorder)the BST");
puts("Enter 4: EXIT");
puts("Enter your choice");
scanf("%d",&sel);
if((sel<1)||(sel>4))
{
puts("Wrong choice");
getchar();
}
}
while((sel<1)||(sel>4));
return sel;
}

struct node *insert(struct node *tree,long digit)
{
if(tree==NULL)
{
tree=(struct node *)malloc(sizeof(struct node));
tree->left=tree->right=NULL;
tree->num=digit;
}
else
if(digit<tree->num)
  tree->left=insert(tree->left,digit);
else if(digit>tree->num)
 tree->right=insert(tree->right,digit);
else if(digit==tree->num)
{
   puts("Duplicate nodes are not allowed");
   getch();
   exit(0);
}
return(tree);
}

struct node *copy(struct node *tree)
{
second=(struct node *)malloc(sizeof(struct node));
head=second;
if(tree!=NULL)
{
second->num=tree->num;
if(tree->left!=NULL)
{
second->left->num=tree->left->num;
copy(tree->right);
}
if(tree->right!=NULL)
{
second->right->num=tree->num;
copy(tree->left);
}
}
return(head);
}

void inorder(struct node *tree)
{
if(tree!=NULL)
{
inorder(tree->left);
printf("%12ld\n",tree->num);
inorder(tree->right);
}
}

