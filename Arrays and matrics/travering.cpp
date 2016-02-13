/* Traversing of the array */


#include <stdio.h>
#include <conio.h>
void main ( )
{
int n, i, a[20];
clrscr ();
printf ("Enter the length of array");
scanf ("%d", &n);
printf ("Enter the elements\n");
for (i=0; i<= n-1; i++)
{
scanf ("%d", &a[i]);
}
printf ("Traversing of the array: \n");
for (i = 0; i<= n-1; i++)
{
printf ("\n%d",a[i]);
}
getch ();
}