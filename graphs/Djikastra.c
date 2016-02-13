#include<stdio.h>
#define infinity 999;
int n,a[10][10]={0},i,j,s,d[10],x[10],k=0,vis[10]={0},min=infinity;
void dij()
{

	int v=0,q=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(d[i]<min && vis[i]==0)
			{
				v=i;
				min=d[i];
			}
		}
		vis[v]=1;
		for(i=0;i<n;i++)
		{
			if(a[v][i]!=0)
			{
				q=min+a[v][i];
				if(d[i]>q)
					d[i]=q;
			}
		}
		min=infinity;
	}
	return;
}

main()
{

	FILE *fp;
	fp=fopen("graph.txt","r+");

	fscanf(fp,"%d",&n);
    printf("\n\n\t\tThe adjency matrix is : \n\t\t\t");
	for(i=0;i<n;i++)
		{
            for(j=0;j<n;j++)
            {
    			fscanf(fp,"%d",&a[i][j]);
    			printf("%d ",a[i][j]);
            }
            printf("\n\t\t\t");
        }
      
	printf("\n\n\t\tEnter Source Vertex : ");
	scanf("%d",&s);

	for(i=0;i<n;i++)
		if(i==s-1)
			d[i]=0;
		else
			d[i]=infinity;
	dij();

	for(i=0;i<n;i++)
	{
		if(i!=s-1)
			printf("\n\n\t\tShortest Distance from %d to %d =%d\n",s,i+1,d[i]);


	}
	getch();
}
