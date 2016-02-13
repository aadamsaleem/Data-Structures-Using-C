/* Array implementation of sparse matrix */


#include <stdio.h>
#include <conio.h>
#define MAX 50
struct triplet {
int row;
int col;
int element;
} spmatrix [MAX];
void main ( )
{
clrscr();
int i, j, n, row, col;
int k = 0;
printf ("\n Enter matrix dimension :");
scanf ("%d %d", &row, &col);
printf ("\n Enter no. of non-zero elements in sparse matrix");
scanf ("%d", &n);
for (i=0;i<n; i++)
{
printf("\n Enter element row, column and its value");
scanf ("%d %d %d", &spmatrix[i].row, &spmatrix[i].col,&spmatrix[i].element);
}
printf ("\n sparse matrix is :");
for (i=0;i<row; i++)
{
printf ("\n");
for (j=0;j<col; j++)
{
if((spmatrix [k].row ==i)&&(spmatrix[k].col==j))
{
printf ("\t%d", spmatrix [k].element);
k++;
}
else
printf ("\t0");
}
}
getch();
}
