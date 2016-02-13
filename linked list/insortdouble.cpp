/* Insertion in sorted doubly linklist*/

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
void insert_sorted ( );
create ( );
ftraverse ( );
insert_sorted ( );
printf(" \n Doubly linklist after insertion is: \n");
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
printf ("\nInput next node in increasing order\n");
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
printf ("forward Traversing :\n");
ptr = first;
while (ptr != NULL)
{
printf ("%d \n", ptr -> info);
ptr = ptr -> rpt;
}
}
void insert_sorted ( )
{
struct node *ptr,*cpt,*tpt;
ptr = (struct node *) malloc (sizeof (struct node));
if (ptr == NULL)
{
printf ("OVERFLOW");
return;
}
printf ("Input new node information");
scanf ("%d", &ptr -> info);
cpt = first;
while (cpt -> info < ptr -> info)
{
cpt = cpt-> rpt;
tpt = cpt -> lpt;
}
tpt -> rpt = ptr;
ptr -> lpt = tpt;
ptr -> rpt = cpt;
cpt -> lpt = ptr;
printf ("Insertion is done\n");
}