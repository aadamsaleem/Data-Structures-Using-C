/* Polynomial addition in single linklist*/

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
struct node *addition_poly(struct node *,struct node *);
struct node *create(struct node *);
struct node *traverse(struct node *);
void main ( )
{
clrscr();
struct node *p1_start,*p2_start,*p3_start;

	p1_start=NULL;
	p2_start=NULL;
	p3_start=NULL;

	printf("Polynomial 1 :\n");
	p1_start=create(p1_start);

	printf("Polynomial 2 :\n");
	p2_start=create(p2_start);

	p3_start=addition_poly(p1_start,p2_start);

	printf("Polynomial 1 is :  ");
	traverse(p1_start);
	printf("Polynomial 2 is :  ");
	traverse(p2_start);
	printf("Added polynomial is :  ");
	traverse(p3_start);
}
create ()
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
void traverse ()
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

void addition_poly ()
{
struct node *ptr1, *ptr2, *ptr, *cpt;
ptr = (struct node *) malloc (sizeof (struct node));
ptr1 = first1;
ptr2 = first2;
first3 = ptr;
If (ptr1 -> expo > ptr2 -> expo)
{
ptr -> coff = ptr1 -> coff;
ptr -> expo = ptr1 -> expo;
ptr1 = ptr1 -> link;
}
else
if (ptr2 -> expo > ptr1 -> expo)
{
ptr -> coff = ptr2 -> coff;
ptr -> expo = ptr2 -> expo;
ptr2 = ptr2 -> link;
}
else
{
ptr -> coff = ptr1 -> coff + ptr2 -> coff;
ptr -> expo = ptr1 -> expo
ptr1 = ptr1 -> link;
ptr2 = ptr2 -> link;
}
while (ptr1 != NULL && ptr2 != NULL)
{
cpt = (struct node *) malloc (sizeof (struct node));
if (ptr1 -> expo > ptr2 -> expo)
{
cpt -> coff = ptr1 -> coff;
cpt -> expo = ptr1 -> expo;
ptr1 = ptr1 -> link;
}
else if (ptr2 -> expo > ptr1 -> expo)
{
cpt -> coff = ptr2 -> coff;
cpt -> expo = ptr2 -> expo;
ptr2 = ptr2 -> link;
}
else
{
cpt -> coff = ptr1 -> coff + ptr2 -> coff
cpt -> expo = ptr1 -> expo;
ptr1 = ptr1 -> link;
ptr2 = ptr2 -> link;
}
ptr -> link = cpt;
ptr = cpt;
}
while (ptr!= NULL)
{
cpt = (struct node *) malloc (sizeof (struct node));
cpt -> coff = ptr1 -> coff;
cpt -> expo = ptr1 -> expo;
ptr1 = ptr1 -> link;
ptr -> link = cpt;
ptr = cpt;
}
while (ptr2 != NULL)
{
cpt = (struct node *) malloc (sizeof (struct node));
cpt -> coff = ptr2 -> coff;
cpt -> expo = ptr2 -> expo;
ptr2 = ptr2 -> link;
ptr-link = cpt;
ptr = cpt;
}
ptr-link = NULL ;
}