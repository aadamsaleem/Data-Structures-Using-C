/* Sum of the diagonal elements*/


#include <stdio.h>
#include <conio.h>
void main ( )
{
int a [5][5], i, j, sum r, c;
sum = 0;
printf ("Enter row and column of matrix is");
scanf ("%d %d", &r, &c);
printf ("Enter elements \n");
for (i=0; i<r; i++)
{
for (j=0, j<c; j++)
{
scanf ("%d", &a[i][j]);
if (i==j)
sum = sum + a[i][j];
}
}
printf ("The sum of the diagonal elements = %d", sum);
}
