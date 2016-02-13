/* Symmetric matrix */

#include <stdio.h>
#include <conio.h>
void main()
{
clrscr();
int a[10][10], n, i, j, flag;
printf ("Enter the order of the matrix;");
scanf ("%d", &n);
printf ("Enter matrix : \n");
for (i=0;i<=n-1; i++)
{
for (j=0; j<=n-1; j++)
{
scanf ("%d", &a[i][j]);
}
}
flag = 1;
for (i=0; i<=n-1; i++)
{
for (j=i+1; j<=n-1; j++)
{
if (a[i][j]-a[j][i] != 0)
flag = 0;
}
}
if (flag)
{
printf ("Given matrix is symmetric matrix");
}
else
{
printf ("Not Symmetric matrix");
}
getch ( );
}
