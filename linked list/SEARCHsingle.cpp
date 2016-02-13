/* Search an element in single linklist*/

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
	 void search ( );
	 clrscr ( );
	 create ( );
	 traverse( );
	 search ( );
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

void search ( )
{
struct node *ptr;
int data;
ptr = first;
printf ("Input information of node to be search");
scanf ("%d", &data);
while (ptr!= NULL)
{
if (ptr-> info == data)
{
printf ("Search is successfull\n");
return;
}
ptr = ptr ->link;
}
printf ("This element does not exist\n");
}