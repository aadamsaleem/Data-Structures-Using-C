 /*Sorting of whole matrix elements.*/

#include <stdio.h>
#include <conio.h>
void main ( )
{
clrscr();
int a[20][20], b[400], i, j, t, k, nr, nc;
printf ("Input total number of rows and columns");
scanf ("%d %d", &nr, &nc);
k = 0;
for (i=0; i<nr; ++i)
for (j=0; j<nc; ++j)
{
printf ("Input elements:");
scanf ("%d", &a[i][j]);
b[k++] = a[i][j];
}
/* Sorting Part */
for (i=0; i<k-1; ++i)
for (j=i+1;j<k; ++j)
if (b[i] > b[j])
{
t = b[i];
b[i] = b[j];
b[j] = t;
}
k=0;
printf ("\n Sorted matrix :\n");
for (i=0; i<nr; ++i)
{
for (j=0; j<nc; ++j)
{
a[i][j] = b[k++];
printf ("%4d", a[i][j]);
}
printf ("\n");
}
getch ( );
}
