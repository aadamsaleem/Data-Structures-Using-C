/* Insert at beginning */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
void main ( )
{
int a[max], i, j;
clrscr ();
printf ("\n Enter Maximum size");
scanf ("%d", &j);
if (j>=max)
{
printf ("\n array size doesn’t fulfill demand");
exit (0);
}
printf ("\n Enter Elements");
for (i=0; i < j; i++)
scanf ("%d", &a[i]);
for (i=j;i > 0; i--)
a[i]=a[i-1];
printf ("\n Enter new element");
scanf ("%d", &a[0]);
printf ("\n After Insert at beginning the new array is \n");
j++;
for (i=0; i<j; i++)
printf ("%d ,", a[i]);
getch ();
}