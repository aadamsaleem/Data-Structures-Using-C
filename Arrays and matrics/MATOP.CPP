/* Various operations on matrices */

#include <stdio.h>
#include <conio.h>
void create (int[3][3]);
void display (int[3][3]);
void add(int[3][3], int[3][3], int[3][3]);
void sub(int[3][3], int[3][3], int[3][3]);
void mul(int[3][3], int[3][3], int[3][3]);
void transpose(int[3][3], int[3][3]);
void main ( )
{
int matrix1[3][3], matrix2[3][3], matrix3[3][3];
clrscr ( );
printf ("Enter first matrix \n");
create (matrix1);
printf ("\nEnter second matrix \n");
create (matrix2);
printf ("\nFirst Matrix is:\n");
display (matrix1);
printf ("Second Matrix is:\n");
display (matrix2);
add(matrix1, matrix2, matrix3);/*Call to function add */
printf ("\n Addition of Matrices:\n");
display (matrix3);
sub(matrix1, matrix2, matrix3);/*Call to function sub */
printf ("\n Subtraction of Matrices:\n");
display (matrix3);
mul(matrix1, matrix2, matrix3);
printf ("\n Multiplication:\n"); /* Call to function mul */
display (matrix3);
printf ("\n Transpose of Matrix 1:\n");
transpose(matrix1, matrix3);/*Call to function transpose */
display (matrix3);
getch ( );}
/* Creates a matrix */
void create (int mat[3][3])
{
int i,j;
for(i=0;i<=2; i++)
{
for (j=0; j<=2; j++)
{
printf ("Enter the element:");
scanf ("%d", &mat[i][j]);
}
}
}
/* Display matrix */
void display(int mat[3][3])
{
int i,j;
for(i=0; i<=2; i++)
{
for(j=0; j<=2; j++)
{
printf ("%4d", mat[i][j]);
}
printf("\n");
}
}
/* Add matrices */
void add(int mat1[3][3], int mat2[3][3], int mat3[3][3])
{
int i,j;
for(i=0; i<=2; i++)
{
for(j=0; j<=2; j++)
{
mat3[i][j] = mat1[i][j] + mat2[i][j];
}
}
}
/* Subtract matrices */
void sub(int mat1[3][3], int mat2[3][3], int mat3[3][3])
{
int i,j;
for(i=0; i<=2; i++)
{
for(j=0; j<=2; j++)
{
mat3[i][j] = mat1[i][j] - mat2[i][j];
}
}
}
/* Multiply matrices */
void mul(int mat1[3][3], int mat2[3][3], int mat3[3][3])
{
int i,j,k;
for(k=0; k<=2; k++)
{
for(i=0; i<=2; i++)
{
mat3[k][i]=0;
for(j=0; j<=2; j++)
mat3[k][i]+=mat1[k][j] *mat2[j][i];
}
}
}
/* Transpose of a matrix */
void transpose(int m1[3][3], int m2[3][3])
{
int i,j;
for(i=0; i<=2; i++)
{
for(j=0; j<=2; j++)
{
m2[i][j]=m1[j][i];
}
}
}

