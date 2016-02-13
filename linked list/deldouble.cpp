/* Deletion in Doubly linklist */
/* Data Structures Using C by UDIT AGARWAL */

# include <stdio.h>
# include <conio.h>
# include <alloc.h>
struct node
{
int info;
struct node *lpt;
struct node *rpt;
};
struct node *first;
void main ( )
{
clrscr();
void create ( );
void ftraverse ( );
void delete_beg ( );
void delete_end ( );
void delete_given_node ( );
create ( );
ftraverse ( );
delete_beg ( );
printf(" \n Doubly linklist after DELETION at beginning: \n");
ftraverse ( );
delete_end ( );
printf(" \n Doubly linklist after DELETION at end: \n");
ftraverse ( );
delete_given_node ( );
ftraverse ( );
getch ( );
}
void create ( )
{
struct node *ptr, *cpt;
char ch;
ptr = (struct node *) malloc (sizeof (struct node));
printf ("\n Input first node information");
scanf ("%d", & ptr -> info);
ptr -> lpt = NULL;
first = ptr;
do
{
cpt = (struct node *) malloc (sizeof (struct node));
printf ("\nInput next node :\n");
scanf ("%d", & cpt -> info);
ptr -> rpt = cpt;
cpt -> lpt = ptr;
ptr = cpt;
printf ("Press <Y/N> for more node \n");
ch = getche ( );
}
while (ch== 'Y');
ptr -> rpt = NULL;
}
void ftraverse ( )
{
struct node *ptr;
printf ("Traversing of linklist is:\n");
ptr = first;
while (ptr != NULL)
{
printf ("%d \n", ptr -> info);
ptr = ptr -> rpt;
}
}
void delete_beg ( )
{
struct node *ptr;
if(first == NULL)
{
printf ("Underflow\n");
return;
}
ptr=first;
first = ptr -> rpt;
first -> lpt = NULL;
free(ptr);
}

void delete_end ( )
{
struct node *ptr, *cpt;
if (first == NULL)
{
printf ("Underflow\n");
return;
}
ptr = first;
while (ptr -> rpt!= NULL)
{
cpt = ptr;
ptr = ptr -> rpt;
}
cpt -> rpt = NULL;
free (ptr);
printf ("Deletion is done\n");
}

void delete_given_node ( )
{
struct node *ptr, *cpt, *tpt;
int m;
if(first == NULL)
{
printf ("Underflow");
return;
}
printf ("\n Node to be deleted is");
scanf ("%d", &m);
ptr = first;
while (ptr -> info != m)
ptr = ptr -> rpt;
cpt = ptr -> lpt;
tpt = ptr -> rpt;
cpt -> rpt = tpt;
tpt -> lpt = cpt;
free (ptr);
printf ("Deletion is done\n");
}