/* BUBBLE SORT */

#include<stdio.h>
#include<conio.h>
#define MAXSIZE 50

void bubble(int x[],int n)
{
int i,j,tmp;

for(i=0;i<n;i++)
{
	for(j=0;j<n-1;j++)
	{
		if(x[j]>x[j+1])
		{
			tmp=x[j];
			x[j]=x[j+1];
			x[j+1]=tmp;
		}
	}
}
}
void main()
{
int x[MAXSIZE],n,i;
clrscr();
	
printf("Enter the number of elements: ");
scanf("%d",&n);

printf("\nEnter the elements: \n");
for(i=0;i<n;i++)
scanf("%d",&x[i]);

bubble(x,n);

printf("\nThe sorted output:\n");
for(i=0;i<n;i++)
printf("\n%d",x[i]);
getch();
}
