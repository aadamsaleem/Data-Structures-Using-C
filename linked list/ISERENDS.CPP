/* Insertion at end in single linklist*/

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
	 void insert_end ();
	 clrscr ( );
	 create ( );
	 traverse( );
	 insert_end ( );
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
printf ("Traversing of link list:\n");
ptr = first;
while( ptr != NULL)
{
printf ("%d\n", ptr ->info);
ptr = ptr -> link;
}
}

void insert_end ( )
{
struct node *ptr,*cpt;
ptr = (struct node*) malloc (sizeof (struct node));
if (ptr == NULL)
{
printf ("overflow\n");
return;
}
printf ("Input New Node information");
scanf ("%d", &ptr -> info);
cpt=first;
while(cpt->link!=NULL)
cpt=cpt->link;
cpt->link=ptr;
ptr->link=NULL;
}