/* Count positive and negative numbers*/

#include <stdio.h>
#include <conio.h>
void main ( )
{
clrscr();
int a [50], n,count_neg=0,count_pos=0,i;
printf ("Enter the size of the array\n");
scanf ("%d", &n);
printf ("Enter the elements of the array\n");
for (i = 0; i < n; i++)
scanf ("%d", &a[i]);
for (i = 0; i < n; i++)
{
if(a[i] < 0)
count_neg++;
else
count_pos++;
}
printf ("There are %d negative numbers in the array\n", count_neg);
printf ("There are %d positive numbers in the array\n", count_pos);
getch();
}