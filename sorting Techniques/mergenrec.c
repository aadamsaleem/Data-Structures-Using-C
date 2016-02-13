/* IMPLEMENT MERGE SORT WITHOUT RECURSION */

#include<stdio.h>
#include<conio.h>
#define MAX 20
void main()
{
int a[MAX],temp[MAX],i,j,k,n,size,l1,h1,l2,h2;
clrscr();
printf ("\nEnter the number of elements : ");
scanf ("%d",&n);
for (i=0;i<n;i++)
{
printf ("\nEnter element %d :",i+1);
scanf ("%d",&a[i]);
}
printf ("\nUnsorted list is :");
for ( i = 0 ; i<n ; i++)
printf("%d", a[i]);
/*l1 lower bound of first pair and so on*/
for (size=1; size < n; size=size*2 )
{
l1 = 0;
k = 0; /*Index for temp array*/
while( l1+size < n)
{
h1=l1+size-1;
l2=h1+1;
h2=l2+size-1;
if ( h2>=n )
h2=n-1;
/*Merge the two pairs with lower limits l1 and l2*/
i=l1;
j=l2;
while(i<=h1 && j<=h2 )
{
if ( a[i] <= a[ j] )
temp[k++]=a[i++];
else
temp[k++]=a[ j++];
}
while(i<=h1)
temp[k++]=a[i++];
while( j<=h2)
temp[k++]=a[ j++];
l1 = h2+1; /*Take the next two pairs for merging */
}

for (i=l1; k<n; i++) /*any pair left */
temp[k++]=a[i];
for(i=0;i<n;i++)
a[i]=temp[i];
printf ("\nSize=%d \nElements are : ",size);
for ( i = 0 ; i<n ; i++)
printf ("%d", a[i]);
}

printf ("\nSorted list is :\n");
for ( i = 0 ; i<n ; i++)
printf ("%d", a[i]);
getch();
}
