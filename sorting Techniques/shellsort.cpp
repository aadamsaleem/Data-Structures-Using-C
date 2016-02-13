/* Shell Sort */
#include <stdio.h>
#include <conio.h>
#define MAX 15
void main( )
{
int arr[MAX], i,j,k,n,incr;
clrscr( );
printf("\nEnter the number of elements :");
scanf ("%d",&n);
for (i=0;i < n;i++)
{
printf ("\nEnter element %d :", i+1);
scanf("%d",&arr[i]);
}
printf ("\nUnsorted list is :\n");
for (i = 0; i < n; i++)
printf("%d  ",arr[i]);
printf ("\nEnter maximum increment (odd value) :");
scanf("%d", &incr);
/*Shell sort algorithm is applied */
while(incr >=1)
{
for (j=incr;j<n;j++)
{
k=arr[j];
for (i=j-incr; i >= 0 && k < arr[i]; i = i-incr)
	arr[i+incr] = arr[i];
arr[i+incr] = k;
}
incr=incr-2; /*Decrease the increment */
}
printf("\nSorted list is : \n\n");
for (i = 0; i < n; i++)
	printf("%d ", arr[i]);
getch( );
}
