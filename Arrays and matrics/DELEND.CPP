/* Deletion at last */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
void main ( )
{
int a[max], i, j ;
clrscr ( );
printf ("\n Enter limit");
scanf ("%d", &j);
if (j>=max)
{
printf ("\n size not exit");
exit (0);
}
printf ("\n Enter Elements of Array:\n");
for (i = 0; i<j; i++)
{
scanf ("%d", &a[i]);
}
j--;
printf ("\n Array Elements after deletion at end :\n");
for (i=0; i <j; i++)
{
printf ("%d ", a[i]);
}
getch();
}
