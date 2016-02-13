/* creation of polynomial*/
# include <stdio.h>
# include <conio.h>
# include <alloc.h>
struct node
{
int coff;
int expo;
struct node *link;
};
struct node *first;
void main ( )
{
clrscr();
void create ( ), traverse ( );
create ( );
traverse ( );
getch ( );
}
void create ( )
{
struct node *ptr, *cpt;
char ch;
ptr = (struct node *) malloc (sizeof (struct node));
printf ("\n Input first term coefficient and exponent");
scanf ("%d %d", & ptr ->coff, & ptr ->expo);
first = ptr;
do
{
cpt = (struct node *) malloc (sizeof (struct node));
printf ("\n Input next term:");
scanf ("%d %d", & cpt ->coff, & cpt ->expo);
ptr ->link = cpt;
ptr = cpt;
printf ("Press <Y/N> for more node \n");
ch = getche ( );
}
while (ch == 'Y');
ptr ->link = NULL;
}
void traverse ( )
{
struct node *ptr;
printf ("\n Terms of polynomials are :\n");
ptr = first;
while (ptr != NULL)
{
printf("%d X^%d + ", ptr->coff,ptr->expo);
ptr = ptr ->link;
}
printf("\b\b \n");
getch ( );
}