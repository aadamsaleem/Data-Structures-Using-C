/* Insertion Sort */

#include<stdio.h>
#include<conio.h>

void insertion(int x[],int n)
{
int i,j,temp;

for(i=0;i<n;i++)
{
	temp=x[i];

	for(j=i-1;j>=0;j--)
	{
		if(temp<x[j])
			x[j+1]=x[j];
		else
			break;
	}

	x[j+1]=temp;
}
}


void main()
{
int x[10],n,i;
clrscr();
printf("Enter the number of elements: ");
scanf("%d",&n);

printf("\nEnter the elements: \n");
for(i=0;i<n;i++)
scanf("%d",&x[i]);

insertion(x,n);

printf("\nThe sorted output:\n");
for(i=0;i<n;i++)
printf("\n%d",x[i]);

getch();
}
