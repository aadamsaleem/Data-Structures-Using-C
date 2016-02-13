/*deletion OF GIVEN node in single linklist*/
/* Data Structures Using C by UDIT AGARWAL */

# include <stdio.h>
# include <conio.h>
# include <alloc.h>
struct node
   {
           int info;
           struct node *link;
     };
struct node *first;

void main ( )

   {
	 void create ();
	 void traverse ();
	 void delete_given_info ( );
	 clrscr ( );
	 create ( );
	 traverse( );
	 delete_given_info ( );
	 printf ("\n After deletion OF GIVEN node");
	 traverse( );
     getch ( );
    }

void create ( )
  {
  struct node * ptr, *cpt;
  char ch;
  ptr = (struct node*) malloc (sizeof (struct node));
  printf ("Input first node information");
  scanf ("%d", &ptr->info);
  first=ptr;
  do
    {
      cpt=(struct node*) malloc(sizeof(struct node));
      printf("Input next node information");
      scanf("%d",&cpt->info);
      ptr->link = cpt;
      ptr = cpt;
   printf ("Press <Y/N> for more node");
     ch = getch ( );
    }
while (ch=='Y');
ptr -> link = NULL;
}

void traverse ( )
{
struct node *ptr;
printf ("\n Traversing of link list:\n");
ptr = first;
while( ptr != NULL)
{
printf ("%d\n", ptr ->info);
ptr = ptr -> link;
}
}

void delete_given_info ( )
{
struct node *ptr, *cpt;
int data;
if (first == NULL)
{
printf ("underflow\n");
return;
}
ptr = first;
printf ("Input information of node to be deleted");
scanf ("%d", &data);
while (ptr->info!= data)
{
cpt = ptr;
ptr = ptr ->link;
}
cpt ->link = ptr ->link;
free (ptr);
}