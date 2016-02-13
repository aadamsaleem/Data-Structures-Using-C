#include<stdio.h>
#define infinity 999;
int d[10],a[10][10],n,i,j,s,q,k;
main()
{

	FILE *fp;
	fp=fopen("graph.txt","r+");

	fscanf(fp,"%d",&n);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			fscanf(fp,"%d",&a[i][j]);
	printf("Enter Source Vertex ");
	scanf("%d",&s);

	for(i=0;i<n;i++)
		if(i==s-1)
			d[i]=0;
		else
			d[i]=infinity;

	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				if(a[j][k]!=0)
				{
					q=d[j]+a[j][k];
					if(d[k]>q)
						d[k]=q;
				}
	}


	for(j=0;j<n;j++)
		for(k=0;k<n;k++)
			if(a[j][k]!=0)
			{
				q=d[j]+a[j][k];
				if(d[k]>q)
					printf("Negative Cycle Exists !!\n");
			}

	for(i=0;i<n;i++)
		printf("%d ",d[i]);
    getch();
}
