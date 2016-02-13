/*Inverse of an array*/

#include <stdio.h>
#include <conio.h>
void main ( )
{
int a[5], i, j, tmp ;
clrscr ( );
printf ("\n Enter Array Element");
for (i=0; i<=4; i++)
{
scanf ("%d", &a[i]);
}
for (i=0; i<=4; i++)
{
printf ("%d address of %d\n",&a[i],a[i]);
}
i = 0;
j = 4;
while (i<j)
{
tmp = a[i];
a[i] = a[j];
a[j] = tmp;
i++;
j--;
}
printf ("\n Inverse of Array is :\n");
for (i=0; i<=4; i++)
{
printf ("Now %d address of %d\n",&a[i],a[i]);
}

getch ();
}