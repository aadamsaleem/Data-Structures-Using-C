/* Circular linklist */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct node
{
int info;
struct node *link;
};
struct node *first;

void main ( )
{
void create ( ), traverse ( ), insert_beg ( ), insert_end ( ),
delete_beg ( ), delete_end ( );
clrscr ( );
create ( );
printf ("\n Circular linklist is :\n");
traverse ( );
insert_beg ( );
printf ("\n Circular linklist after inserting in beginning is :\n");
traverse ( );
insert_end ( );
printf ("\n Circular linklist after inserting at end is :\n");
traverse ( );
delete_beg ( );
printf ("\n Circular linklist after deleting from beginning is :\n");
traverse ( );
delete_end ( );
printf ("\n Circular linklist after deleting from end is :\n");
traverse ( );
getch ( );
}

void create ( )
{
struct node *ptr, *cpt;
char ch;
ptr = (struct node *) malloc (sizeof (struct node));
printf ("Input first node");
scanf ("%d",&ptr->info);
first = ptr;
do
{
cpt = (struct node *) malloc (sizeof (struct node));
printf ("Input next node");
scanf ("%d", &cpt -> info);
ptr -> link = cpt;
ptr = cpt;
printf ("Press <Y/N> for more node");
ch = getche ( );
}
while (ch =='Y');
ptr ->link = first;
}
void traverse ( )
{
struct node *ptr;
printf ("Traversing of link list:\n");
ptr = first;
do
{
printf ("%d\n",ptr-> info);
ptr = ptr->link;
}
while (ptr != first);
}

void insert_beg ( )
{
struct node *ptr,*cpt;
ptr = (struct node *) malloc (sizeof (struct node));
if (ptr ==NULL)
{ 
	printf ("overflow\n");
return;
}
printf ("Input new node");
scanf ("%d", &ptr -> info);
cpt = first;
while (cpt ->link != first)
{
cpt = cpt ->link;
}
ptr -> link = first;
first = ptr;
cpt -> link = first;
}
void insert_end ( )
{
struct node *ptr, *cpt;
ptr = (struct node *) malloc (sizeof (struct node));
if (ptr ==NULL)
{
printf ("overflow\n");
return;
}
printf ("Input new node to insert at END \n ");
scanf ("%d", &ptr -> info);
cpt = first;
while (cpt -> link != first)
cpt = cpt -> link;
cpt -> link = ptr;
ptr -> link = first;
}
void delete_beg( )
{
struct node *ptr, *cpt;
if (first == NULL)
{
printf ("underflow\n");
return;
}
cpt = first;
while (cpt -> link != first)
cpt = cpt -> link;
ptr = first;
first = ptr -> link;
cpt -> link = first;
free (ptr);
}
void delete_end( )
{
struct node *ptr, *cpt;
if (first == NULL)
{
printf ("underflow\n");
return;
}
cpt = first;
while (cpt -> link != first)
{
ptr = cpt;
cpt = cpt -> link;
}
ptr -> link = first;
free (cpt);
}