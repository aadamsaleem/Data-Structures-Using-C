/* Traversing in Double linklist*/
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
void btraverse ( );
create ( );
btraverse ( );
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
void btraverse ( )
{
struct node * ptr ;
printf ("\n Backward traversing :\n");
ptr = first ;
while (ptr -> rpt!= NULL)
ptr = ptr -> rpt ;
while (ptr != NULL)
{
printf ("%d\n", ptr -> info);
ptr = ptr -> lpt;
}
}