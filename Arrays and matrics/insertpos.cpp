/*Insertion at given position*/

#include <stdio.h>
#include <conio.h>
void main ()
{
clrscr();
int i, j, k, n, pos;
float a[50], item;
printf("Size of the array");
scanf("%d",&n);
printf("\n Array elements \n");
for (i=0; i<n; i++)
scanf("%f", & a[i]);
printf("\n Element to be inserted?");
scanf("%f",&item);
printf("\n Position of insertion ?");
scanf("%d",&pos);
/*Pushing down the elements*/
n++;
for (k=n; k>=pos; k--)
a[k] = a[k-1];
a[--pos] = item;
printf("\n Array after insertion; \n");
for (i=0; i<n; i++)
printf("%6.2f", a[i]);
printf("\n");
getch();
}
