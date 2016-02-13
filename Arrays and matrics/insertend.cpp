/*Insertion at last position */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
void main ( )
{
clrscr();
int a[max], i, j, n;
printf ("\n Enter limit");
scanf ("%d", &j);
if (j>=max)
{
printf ("\n size of limit doesn't match");
exit (0);
}
printf ("\n Enter new element");
for (i = 0; i<j; i++)
{
scanf ("%d", &a[i]);
}
printf ("\n Enter Element");
scanf ("%d", &n);
a[j]=n;
printf ("\n Array after insertion at end is:\n");
for (i = 0; i<=j; i++)
printf ("%d ,",a[i]);
getch ( );
}
