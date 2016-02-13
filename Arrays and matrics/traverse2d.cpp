/* Traversing a two dimensional array */

#include <stdio.h>
#include <conio.h>
int i,j;
int A[10][10];
void traverse (int, int);
void create (int, int);

void create (int row, int col)
{
printf("\n Input value:\n");
for (i=0;i<row; i++)
{
for (j=0;j<col; j++)
{
scanf("%d",&A[i][j]);
}
}
}
void traverse (int row,int col)
{
printf ("\n Traversing in column major order : \n");
for (j=0;j<col; j++)
{
for (i=0;i<row; i++)
{
printf ("%d ",A[i][j]);
}
printf ("\n");
}
printf ("\n Traversing in row major order : \n");
for (i=0;i<row; i++)
{
for (j=0; j<col; j++)
{
printf ("%d ", A[i][j]);
}
printf ("\n");
}
}
void main ( )
{
clrscr();
int r,c;
printf("\n Input the no. of rows");
scanf ("%d", &r);
printf ("\n Input the no. of columns");
scanf ("%d", &c);
create (r,c);
traverse (r,c);
getch();
}