/* Insertion in doubly linklist*/
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
void insert_beg ( );
void insert_end ( );
void insert_given_node ( );
create ( );
ftraverse ( );
insert_beg ( );
printf(" \n Doubly linklist after insertion at beginning: \n");
ftraverse ( );
insert_end ( );
printf(" \n Doubly linklist after insertion at end: \n");
ftraverse ( );
insert_given_node ( );
printf(" \n Doubly linklist after insertion at given node: \n");
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
printf ("\nInput next node information \n");
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
void insert_beg ( )
{
struct node *ptr;
ptr = (struct node *) malloc (sizeof (struct node));
if (ptr == NULL)
{printf ("OVERFLOW");
return;
}
printf ("Input new node");
scanf ("%d", & ptr -> info);
ptr -> rpt = first;
first -> lpt = ptr;
first = ptr;
printf ("New node is insert\n");
}

void insert_end ( )
{
struct node *ptr, *cpt;
ptr = (struct node *) malloc (sizeof (struct node));
if(ptr == NULL)
{
printf ("OVERFLOW");
return;
}
printf ("Input new node information");
scanf ("%d", & ptr -> info);
cpt = first;
while (cpt -> rpt!= NULL)
cpt = cpt -> rpt;
cpt -> rpt = ptr;
ptr -> lpt = cpt;
ptr -> rpt = NULL;
printf ("Insertion is done\n");
}

void insert_given_node ( )
{
struct node *ptr, *cpt, *tpt;
int m;
ptr = (struct node *) malloc (sizeof (struct node));
if (ptr == NULL)
{
printf ("OVERFLOW");
return;
}
printf ("Input new node information");
scanf ("%d", &ptr -> info);
printf ("\nInput node information after which insertion");
scanf ("%d", &m);
cpt = first;
while (cpt -> info!= m)
cpt = cpt -> rpt;
tpt = cpt -> rpt;
cpt -> rpt = ptr;
ptr -> lpt = cpt;
ptr -> rpt = tpt;
tpt -> lpt = ptr;
printf ("Insertion is done\n");
}