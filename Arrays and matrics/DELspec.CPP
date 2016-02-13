/*Deletion of specific element */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
void main ()
{
int a[max],k,i,j,n;
clrscr();
printf ("\n Enter Limit:");
scanf ("%d",&j);
if (j>max)
{
printf ("\n Array size doesn't exist");
exit (0);
}
printf ("\n Enter Elements in Array:\n");
for (i = 0; i<j; i++)
{
scanf ("%d",&a[i]);
}
printf ("\n Enter element which you want to delete:\n ");
scanf ("%d",&n);
for (i=0;i<j;i++)
{
if (n==a[i])
{
 for (k=i; k<=j-2;k++)
 {
  a[k] = a[k+1];
  }
 j--;
 }
}
printf ("\n Array Elements after elements are :\n");
for (i=0;i<j;i++)
{
printf("%d ",a[i]);0
}
getch();
}