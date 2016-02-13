/* Selection Sort */

#include<stdio.h>
#include<conio.h>
#define MAXSIZE 50

void selection(int x[], int n)
{
int i, j, larg,pos,c=0;
for (i = n-1; i>0; i--){
	larg = x[0];
	pos = 0;
	for (j = 1; j<=i; j++)
	{
	  c++;
		 if (x[j] > larg){
			   larg = x[j];
			   pos = j;
		 }
	}
	x[pos] = x[i];
	x[i] = larg;
	}
	printf("\n Number of comparisons required = %d \n",c);
} /*end of selection sort*/

void main()
{
       int x[MAXSIZE],n, i;
	clrscr();
	printf("\n Enter number of elements ");
	scanf("%d",&n);
	printf("\n Unsorted list is as follows\n");

	for (i = 0; i < n; i++)
	{	printf("\n Enter element %d ",i+1);
		scanf("%d",&x[i]);
	}
	selection(x, n);
	printf("\n Sorted list is:\n\n");

	for (i = 0; i < n; i++)
		printf("%d ", x[i]);
getch();
}
