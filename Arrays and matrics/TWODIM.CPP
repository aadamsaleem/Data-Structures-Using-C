/* Program of two dimension array */

#include <stdio.h>
#include <conio.h>
void main ( )
{
int a [4][4], i, j;
clrscr ( );
printf ("Enter the elements:\n");
for (i=0; i<=3; i++)
{
for (j=0;j<=3; j++)
{
scanf ("%d", &a[i][j]);
}
}
printf ("\nElements of 2D array are :\n");
for (i=0; i<=3; i++)
{
for (j=0;j<=3; j++)
{
printf ("%d ", a[i][j]);
}
printf ("\n");
}
getch ( );
}
