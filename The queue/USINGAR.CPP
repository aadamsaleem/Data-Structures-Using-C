/* Program to implement queue using array */

#include <stdio.h>
#include <conio.h>
#define MAX 100

int q[MAX + 1], front = 0, rear = 0;

void main ( )
{
clrscr();
void create(),traverse(),insert(),delet();
create ( );
traverse ();
insert ( );
printf("\n After insert an element");
traverse();
delet ( );
printf("\nAfter deletion");
traverse ( );
getch ( );
}

void create ( )
{
char ch;
front=1;
do
{
rear++;
printf ("\nInput element in queue:\n");
scanf ("%d", & q[rear]);
printf ("Press <Y/N> for more element");
ch = getch ( );
}
while (ch=='Y');
}

void traverse ( )
{
int i;
printf ("\nelements in the Queue are:\n");
for (i=front; i<=rear;++i)
printf ("%d\n", q[i]);
}

void insert ( )
{
int m;
if (rear == MAX)
{
printf ("Queue is overflow \n");
return;
}
printf ("\nInput new element to insert\n");
scanf ("%d", &m);
rear++;
q[rear]=m;
}

void delet( )
{
if (front==0)
{
printf ("Queue is underflow\n");
return;
}
if (front==rear)
{
q[front] = '\0';
front = rear = 0;
}
else
{
q[front] = '\0';
front++;
}
}
