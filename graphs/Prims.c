#include<stdio.h>
#include<conio.h>
#include<limits.h>

main()
{
	FILE *f = fopen ("a.txt","r");
	int small,smallest,s,i,j,k,l,b[20][20],m,y,n,p[20],total,v[20],t,q,r,a[20][20];

	fscanf(f,"%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
	printf("\n\n\t\tInput Matrix:\n \t\t");

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}printf("\n\t\t");
	}
	printf("\n\t\tMST\n");
	for(i=0;i<20;i++){
		p[i]=-1;
		v[i]=0;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[i][j]=0;
	k=0;
	v[0]=1;
	total=0;
	p[k]=0;
	for(i=1;i<n;i++){
		l=0;
		smallest=100;
		while(p[l]!=-1){
			t=p[l];
			small=100;
			for(j=0;j<n;j++){
				if(a[t][j]<small && a[t][j]>0 && v[j]==0){
					small=a[t][j];
					q=j;
					m=t;
				}
			}
			if(small<=smallest){
				smallest=small;
				r=q;
				y=m;
			}
			l++;
		}
		total+=smallest;
		k++;
		p[k]=r;
		v[r]=1;
		b[y][r]=1;
		s=0;

		printf("\t\t(%c, %c)",y+65,r+65);

		printf("\n");
	}	printf("\n\t\tTotal weight = %d", total);
	getch();
}
