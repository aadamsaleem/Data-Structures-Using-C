#include<stdio.h>
#define size 10
void warshall(int a[size][size],int n)
{
	int k,i,j;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=a[i][j]||(a[i][k] && a[k][j]);
			}
		}
	}
}
int main()
{
	int a[size][size];
	int i,j,k,n;
	printf("\n\n\t\t\tEnter no. of vertices : ");
	scanf("%d",&n);
	printf("\n\t\t\tGive the initial graph(in binary matrix form):\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\t\tEnter the value of a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	warshall(a,n);
	printf("\t\tThe final matrix where we can find the presence of directed path :\n\t\t");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%5d",a[i][j]);
		printf("\n\t\t");
	}
	getch();
    return 0;
}
